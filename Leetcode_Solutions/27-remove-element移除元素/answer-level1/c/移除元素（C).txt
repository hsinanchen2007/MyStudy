### 解题思路
本题关键点在于要善于利用“元素顺序可以改变”这一条件。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i, n = numsSize;
    while(i < n){
        if(nums[i] == val){
            nums[i] = nums[n - 1];
            n--;
        }
        else{
            i++;
        }
    }
    return n;
}
```