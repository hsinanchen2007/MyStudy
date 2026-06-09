### 解题思路
1. i用来依次遍历每个元素
2. j用来记录不同的元素个数
3. 遍历元素的时候，若判断不同，记录此刻元素值后，j增一
4. j总是指向下一个可能的元素，所以j比最大索引值大一，正好可以用作数组长度

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    if(numsSize == 0) return 0;
    int j = 0;
    for(int i = 0;i < numsSize; i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

```