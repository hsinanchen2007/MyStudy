```
/**
* 31 ... 5 4 3 2 1: 5-31位用来存放元素的个数 ， 1-4位用来存放当前元素
*整体思路：
*1.快排原数组
*2.计算每个元素的个数存储在原数组中，维护独立的指针，找出元素个数最小值min
*3.元素最小值min作为外层循环，遍历2-min，如果找到可以同时作为所有元素个数的最小公因数，返回true
*4.返回false
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

bool hasGroupsSizeX( int * deck , int deckSize ){

    //if the length of deck less than 2, return false
    if( deckSize < 2 ){

        return false;

    }

    //the parameter of min used to save the minimun of number of elements in deck
    //the parameter of len used to point the new data in deck 
    int min = 10000 , len = 0;

    //quick sort
    qsort( deck , deckSize , sizeof( int ) , cmp );

    //calculating the number of each eleemnts in deck and updating the value of min 
    for( int i = 0 ;  i < deckSize - 1 ; i++ ){
        
        //updating the number of elements in deck
        *( deck + len ) += 10000;

        //if current elememt is defferent to next element, updating pointer
        if( *( deck + i ) % 10000 != *( deck + i + 1 ) % 10000 ){

            min = min > *( deck + len ) / 10000 ? *( deck + len ) / 10000 : min;
            *( deck + ++len ) = *( deck + i + 1 );


        }

    }

    //if current elememt is defferent to next element, updating pointer
    *( deck + len ) += 10000;
    min = min > *( deck + len ) / 10000 ? *( deck + len ) / 10000 : min;
    len++;

    //if the value of min less than 1, return false
    if( min < 1 ){

        return false;

    }

    //visiting the number from 2 to the value of min
    for( int k = 2 ; k <= min ; k++ ){

        char flag = '1';

        for( int i = 0 ; i < len ; i++ ){

            if( ( *( deck + i ) / 10000 ) % k != 0 ){

                flag = '0';
                break;

            }

        }

        //if current value of k can meet all the condition, return true
        if( flag == '1' ){

            return true;

        }

    }
    
    return false;

}
```
