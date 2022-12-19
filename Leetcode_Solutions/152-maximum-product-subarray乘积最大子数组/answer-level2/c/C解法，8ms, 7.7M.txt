**思路**
先将全部值相乘得到out,如果out > 0则就是最大乘积。
否则则考虑将所有乘积记录下来，取最大值，为防止超时，这里保证计算过程中不重复计算。
计算顺序类似于：1,2,3,4,5---->1---->2,1----->6,3,3---->24,12,12,4----->120,60,60,20,5
*做这道题的时候用了三种方法，中间超时了很多次，一直没用动态规划，也尝试着按0进行分段，但是在倒数第二个用例超时了，因为那个用例中有很多零……*

```
int maxProduct(int* nums, int numsSize){
    int out = 1;
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        out *= nums[i];
        max = (out > max) ? out : max;
    }
    if (out > 0) {
        return out;
    }
    long **array = (long **)malloc(2 * sizeof(long*));
    array[0] = (long *)malloc(numsSize * sizeof(long)); // 用两个数组交替记录结果
    array[1] = (long *)malloc(numsSize * sizeof(long));
    for (int i = 1; i < numsSize; i++) {
        int tmp = nums[i];
        array[(i + 1) & 0x01][i] = tmp;
        max = (max > tmp) ? max : tmp;
        for (int j = 1; j < i; j++) {            
            array[(i + 1) & 0x01][j] = array[i & 0x01][j] * tmp; 
            max = (max > array[(i + 1) & 0x01][j]) ? max : array[(i + 1) & 0x01][j];
        }
    }
    return max;
}


```
