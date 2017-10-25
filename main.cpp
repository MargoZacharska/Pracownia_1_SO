#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void *mainWatku(void *i_priv)
{
	unsigned *i = static_cast<unsigned *>(i_priv);
    cout << "Pisze z watku nr " << (*i) << endl;
    delete i;
    return NULL;
}

int main()
{
	const unsigned NUMBER_OF_THREADS = 7;
    pthread_t threads[NUMBER_OF_THREADS];
	
    for (unsigned i = 1; i <= NUMBER_OF_THREADS; ++i)
    {
		cout << "Tworze watek nr " << i << endl;
		unsigned *i_priv = new unsigned(i);
     	int result = pthread_create(&threads[i - 1], NULL, mainWatku, static_cast<void *>(i_priv));

		if(result)
		{
         	cout << "Error: pthread_create zwrocil " << result << endl;
         	return -1;
        }
    }
    
    for(unsigned i = 1; i <= NUMBER_OF_THREADS; ++i)
    {
    	pthread_join(threads[i - 1], NULL);
    }
    
    cout << "Koniec maina!" << endl;

    return 0;
}

