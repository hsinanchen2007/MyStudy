### 解题思路
元素两两抵消，因出现最多的元素次数大于一半，最后剩下的就是它。
时间复杂度为O(n)

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int candi = nums[0];
    int cnt = 1;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i] == candi)
        {
            cnt++;
        }
        else if(cnt > 0)
        {
            cnt--;
        }
        else
        {
            candi=nums[i];
            cnt=1;
        }
    }
    return candi;
}


```