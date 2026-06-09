```
/**
*
*整体思路：
*1.如果数组长度小于2，直接返回true
*2.过滤掉数组前面元素相等的部分，不断后移到不相等的元素部分
*3.如果此时不相等元素部分的前两个递减，遍历后续数组如果出现递增，直接返回false
*4.如果此时不相等元素部分的前两个递增，遍历后续数组如果出现递减，直接返回false
*5.返回true
*
*/

bool isMonotonic( int * A , int ASize ){

    //if the length of array is less than 2, return true
    if( ASize < 2 ){
        
        return true;

    }

    int i = 1;

    //skipping the elements which are the same in array
    while( i < ASize && *( A + i ) == *( A + i - 1 ) ){

        i++;

    }

    //if the two elements in the staring of this segment is uprising 
    if( i < ASize && *( A + i ) >= *( A + i - 1 ) ){

        for( ; i < ASize ; i++ ){

            if( *( A + i ) < *( A + i - 1 ) ){

                return false;

            }
 
        }

    //if the two elements in the staring of this segment is descending
    } else {

        for( ; i < ASize ; i++ ){

            if( *( A + i ) > *( A + i - 1 ) ){

                return false;

            }
 
        }

    }

    return true;
 
}
```
