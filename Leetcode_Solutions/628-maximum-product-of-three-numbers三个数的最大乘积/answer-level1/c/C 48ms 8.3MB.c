### 解题思路
总体思路：
1.找出数组的最大值，第二大值，第三大值，做乘法
2.找出小于0的最小值，第二小值，
3.（三个最大值乘积）与（小于0的两个最小值和大于0最大值乘积）比较

具体思路：
1.用冒泡程序计算出数组前三个元素的最大，第二小值，第三小值，分别
  复制给first, second, third，同时默认最小值全为0
2.遍历余下数组，与三个最大值和两个最小值比较，更大或更小或者处于中间时，
  更新排序

### 代码

```c
int maximumProduct(int* nums, int numsSize){

/** if the length of array smaller than 3, return 0 
* or when the length of array is 3, if one of the element 
* is 0, also return 0 
*/ 
if( ( numsSize < 3 || numsSize > 10000 ) 
        || ( numsSize == 3 && ( nums[ 0 ] == 0 || nums[ 1 ] == 0 
            || nums[ 2 ] == 0 ) ) ){

        return 0;

    }

    int first = 0 , second = 0 , third = 0;
    int min1 = 0 , min2 = 0;

    //initializing the three big variable through using The bubbling program
    for( int i = 0 ; i < 3 ; i++ ){

        for( int j = 0 ; j < 3 - i - 1 ; j++ ){

            if( nums[ j ] > nums[ j + 1 ] ){

                int tmp = nums[ j ];
                nums[ j ] = nums[ j + 1 ] ;
                nums[ j + 1 ] = tmp;

            }

        }

    }

    first = nums[ 2 ];
    second = nums[ 1 ];
    third = nums[ 0 ];

    min1 = third;
    min2 = second;

    /** comparing the element through visiting the array
    * then updating the maximum or the minimum of value
    */
    for( int i = 3 ; i < numsSize ; i++ ){

        if( nums[ i ] > 0 ){

            if( nums[ i ] > first ){

                //you need to update three value
                third = second;
                second = first;
                first = nums[ i ];

            } else if( nums[ i ] <= first && nums[ i ] > second ){

                //you need to update two value
                third = second;
                second = nums[ i ];

            } else if( nums[ i ] > third && nums[ i ] <= second ){

                //you just need to update one value
                third = nums[ i ];

            }
            
        } else {

            if( nums[ i ] < min1 ){

                //also, you need to update two value
                min2 = min1;
                min1 = nums[ i ];

            } else if( nums[ i ] >= min1 && nums[ i ] < min2 ){

                //the last one you need to update
                min2 = nums[ i ];

            }
        }

    }

    return ( first * second * third ) > ( first * min1 * min2 ) 
                ? ( first * second * third ) : ( first * min1 * min2 ) ;

}
```