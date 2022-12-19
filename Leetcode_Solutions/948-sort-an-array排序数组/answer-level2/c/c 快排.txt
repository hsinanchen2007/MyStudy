```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*
*整体思路：
*1.传入参数数组，以及排序的起始下标p，最终下标r，先判断p < r是否成立，
*2.选定最后一个元素作为划分的标准，遍历[ p, r-1 ]的元素，将所有小于*( nums + r )的元素和指针i指向
*  的元素进行交换，更新指针i
*3.递归调用该函数，进行下两趟的排序
*/


/**
*Function: sorting array to the value of element which index is r
*@param: int * nums : the array ready to be sorted
*@param: int p : the starting index of array
*@param: int r : the ending index of array
*Return: void
*/
void myQsort( int * nums , int p , int r ){

    //if p smaller than r
    if( p < r ){

        int i = p;

        //visiting elements between the index of p to r-1
        for( int j = p ; j < r ; j++ ){

            //if the value of current element smaller than or 
            //equal to the value of last element
            if( *( nums + j ) <= *( nums + r ) ){

                int tmp = *( nums + j );
                *( nums + j ) = *( nums + i );
                *( nums + i++ ) = tmp;


            }

        }

        //exchanging the last element with the element of i
        int tmp = *( nums + r );
        *( nums + r ) = *( nums + i );
        *( nums + i ) = tmp;
        myQsort( nums , p , i - 1 );
        myQsort( nums , i , r );

    }


}

int * sortArray( int * nums , int numsSize , int * returnSize ){

    
    myQsort( nums , 0 , numsSize - 1 );    
    *returnSize = numsSize;

    return nums;

}
```
