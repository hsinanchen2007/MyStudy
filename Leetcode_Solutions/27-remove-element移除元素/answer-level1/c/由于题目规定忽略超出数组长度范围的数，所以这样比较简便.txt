### 解题思路
利用题目规定的忽略 超出返回后数组长度的元素，可以不用大费周章依次移动后续元素；
只需要一个指针cur指向目前不需要删除的元素。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int cur = 0,i;

    for(i = 0;i < numsSize;i++){
        //skip the designative value
        if(nums[i] == val)
            continue;
        nums[cur++] = nums[i];
    }

    return cur;     
}
```