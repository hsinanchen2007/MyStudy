这个题目被returnColumnSizes参数困惑了很久还是不明白，为什么要多余设置这个参数？
最终改来改去，还是本地调试通过，提交服务器失败，错误信息如下。求助大神，到底错在什么地方？源代码如下：

1 / 313 个通过测试用例
执行出错信息：
Line 240: Char 15: runtime error: load of null pointer of type 'int *' (__Serializer__.c)
最后执行的输入：
[]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void BubbleSort(int* nums, int numsSize) {
    int i, j, temp;
    int exchange;
    
    for (i = 0; i < numsSize - 1; i++) {
        exchange = 0;
        for (j = numsSize -1 ; j > i; j--) {
            if (nums[j] < nums[j-1]) {
                temp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = temp;
                exchange = 1;
            }
        }
        if (exchange == 0) {
            break;
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    BubbleSort(nums, numsSize);
    
    if (numsSize < 3 || nums[0] > 0 || (nums[0] + nums[1] + nums[2] > 0)){
        return NULL;
    }
    
    *returnColumnSizes = (int*) malloc(numsSize * numsSize * sizeof(int));
    int **result = (int**) malloc(numsSize * numsSize * sizeof(int*));
    int **p;
    p = result;
    int *pi;
	int size = 0;
    int i;
    int left, right;
   
    for (i = 0; i < numsSize -2 && nums[i] <= 0; i++) {
        left = i + 1;
        right = numsSize -1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            }
            else {
                size++;
                pi = (int*)malloc(3 * sizeof(int));
                if (pi == NULL) {
					return NULL;
				} 
				else {
	                pi[0] = nums[i];
					pi[1] = nums[left];
					pi[2] = nums[right];
					result[size -1] = pi;
				}
				// printf("result[%d],nums=[%d,%d,%d]\n",size - 1, result[size -1] [0], result[size -1] [1], result[size -1] [2]);
                (*returnColumnSizes)[size - 1] = 3;
               
                while ( left + 1 < numsSize && nums[left] == nums[left+1]) {
                    left++;
                }
                while (right - 1 >= 0 && nums[right] == nums[right-1]) {
                    right--;
                }
                left++;
                right--;
            }
        }
        while (i + 1 < numsSize -1 && nums[i+1] == nums[i] ) {
            i++;
        }
    }

    // for (i = 0; i < size; i++) {
    // 	pi = result[i];
    //     printf("end result[%d],nums=[%d,%d,%d]\n",i, pi[0], pi[1], pi[2]);
    // }

    *returnSize = size;
    
	// for (i = 0; i < size; i++) {				//打印
	// 	pi = returnColumnSizes[i];
	// 	printf("end returnColumnSizes[%d]:%d\n",i, pi[0]);
	// }
	
    return result;
}
