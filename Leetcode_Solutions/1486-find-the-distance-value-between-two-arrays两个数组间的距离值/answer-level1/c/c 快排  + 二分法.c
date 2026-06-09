```

/**
*
*整体思路：
*1.首先快排数组arr2，
*2.依次遍历arr1数组元素
*3.利用二分法找到arr2中离当前元素*( arr1 + i )最近的值，计算距离tmp后与d比较，如果满足tmp<d，
*  则表示当前元素必满足距离条件，否则不更新计数器count
*4.返回计数器count的值
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int findTheDistanceValue( int * arr1 , int arr1Size , int * arr2 , int arr2Size , int d ){

    //the parameter of count used to save the number of elements in arr1 
    //which meet the condition
    int count = 0;

    //quick sort arr2
    qsort( arr2 , arr2Size , sizeof( int ) , cmp );

    //visiting arr2, calculating the distance between the value of elements in arr1
    //and the value of elements in arr2 which is more closer it to other
    for( int i = 0 ; i < arr1Size ; i++ ){

        int left = 0 , right = arr2Size , flag = 1;

        while( left < right ){

            int mid = ( left + right ) / 2;

            //comparing the value of *( arr1 + i ) to *( arr2 + mid ), then, 
            //choosing the direction
            if( *( arr1 + i ) < *( arr2 + mid ) ){

                right = mid;

            } else if( *( arr1 + i ) > *( arr2 + mid ) ){

                left = mid + 1;

            }

            //if the value of tmp smaller than the value of d, breaking
            if( abs( *( arr1 + i ) - *( arr2 + mid ) ) <= d  ){

                flag = 0;
                break;

            }

        }

        count += flag;

    }
   

    return count;

}
```
