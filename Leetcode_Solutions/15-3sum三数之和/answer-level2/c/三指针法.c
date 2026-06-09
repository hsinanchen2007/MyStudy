### 解题思路
我自己都快看不懂了，而且感觉有点不对劲，不过总算是跑出来了。。。


### 代码

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}//自定义的比较函数

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    *returnSize = 0;
    if(numsSize <= 2) return NULL;

    int i,Left,Right,tmp1,tmp2,tmp3;
    i = 0;
    int** returnArray = (int**)malloc(sizeof(int*) * (numsSize)*(numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize));
    qsort(nums,numsSize,sizeof(int),comp);

    while(i < numsSize - 2){
        Left = i+1;
        Right = numsSize-1;
        while(Left != Right && Left < Right){
            tmp1 = nums[i];
            tmp2 = nums[Left];
            tmp3 = nums[Right];
            if(nums[i]+nums[Left]+nums[Right] == 0){
                returnArray[*returnSize] = (int*)malloc(sizeof(int) * 3); 
                (*returnColumnSizes)[*returnSize] = 3;
                returnArray[*returnSize][0] = nums[i];
                returnArray[*returnSize][1] = nums[Left];
                returnArray[*returnSize][2] = nums[Right];
                (*returnSize)++;

                Left++;
                while(tmp2 == nums[Left] && Left < numsSize-2){
                tmp2 = nums[Left];
                Left++;
                }

                Right--;
                while(tmp3 == nums[Right] && Right > Left){
                tmp3 = nums[Right];
                Right--;
                }
            }
            else if(nums[i]+nums[Left]+nums[Right] < 0){
                Left++;
            }
            else{
                Right--;
            }
        }

        i++;
        while(tmp1 == nums[i] && i < numsSize-2){
            tmp1 = nums[i];
            i++;
        }
    }
    return returnArray;
}