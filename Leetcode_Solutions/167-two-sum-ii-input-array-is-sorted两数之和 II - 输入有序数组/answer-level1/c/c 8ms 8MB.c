```
/**
*
*整体思路：时间复杂度O(N)，空间复杂度O(2)
*1.如果数组个数少于两个，则无效
*2.分别从左和右端遍历数组，
*3.如果当前两个元素的和大于target，则右端指针right左移一位
*4.如果当前两个元素的和小于target，则左端指针left右移一位
*5.如果等于target，则直接返回
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * twoSum(int * numbers , int numbersSize , int target, int * returnSize){

    //if the length of array is less than 2,
    if( numbersSize < 2 ){

        *returnSize = 0; 

    }
    
    //the parameter of left is used to point the left element of numbers
    //the parameter of right is used to point the right element of numbers
    int left = 0, right = numbersSize - 1;

    *returnSize = 2;

    while( left < right ){

        //if the sum of left and right element is equaling to target, return
        if( *( numbers + left ) + *( numbers + right ) == target ){

            *( numbers + 0 ) = left + 1;
            *( numbers + 1 ) = right + 1;
            
            return numbers;

        //if the sum of left and right element is less to target,
        // moving left to right by one bit and continuing
        } else if( *( numbers + left ) + *( numbers + right ) < target ){

            left++;
            continue;

        } 

        //if the sum of left and right element is less to target,
        //moving right to left by one bit
        right--;

    }

    return numbers;

}
```
