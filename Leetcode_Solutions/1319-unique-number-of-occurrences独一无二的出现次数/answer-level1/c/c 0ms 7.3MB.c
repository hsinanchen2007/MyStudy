```
/**
*
*整体思路：
*1.利用快速排序排列原数组，依次遍历数组，将求得的各个元素的个数存入该数组中
*2.再次使用快速排序，判断最后结果是否有重复个数的，如果有则直接返回
*
*/

//this fun is used to quick sort 
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

bool uniqueOccurrences(int* arr, int arrSize){

    //the parameter of len is used to calculate the length of the updating array;
    //the parameter is used to calculate the number of relating value
    int len = 0 , count = 1;

    //quick sort the array, then calculate each element's number
    qsort( arr , arrSize , sizeof( int ) , cmp );

    for( int i = 0 ; i < arrSize - 1 ; i++ ){

        if( *( arr + i ) != *( arr + i + 1 ) ){

            //keeping move the position of the pointer
            *( arr + len++ ) = count;
            count = 1;

        } else if( *( arr + i ) == *( arr + i + 1 ) ){

            count++;

        }

    }

    //calculating the last element's number, making sure it has been included
    if( count == 1 ){

        *( arr + len++ ) = count;

    }

    //quick the new array according to the len
    qsort( arr , len , sizeof( int ) , cmp );

    for( int i = 0 ; i < len - 1 ; i++ ){

        //once two of the updating array are equaling, return false;
        if( *( arr + i ) == *( arr + i + 1 ) ){

            return false;

        }

    }

    return true;

}
```
