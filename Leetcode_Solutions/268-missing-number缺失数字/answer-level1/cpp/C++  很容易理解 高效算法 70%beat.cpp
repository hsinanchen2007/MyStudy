### 解题思路
观察题目要去和举的例子，若干个连续数字里只缺少一个数字
那么一个很自然的想法即为：
先算出本来的和（因为是连续数字，好算）
减去遍历数组的每一个元素，最后得到的就是缺失的元素

```
int missingNumber(vector<int>& nums) {
        int len=nums.size();
        int total=(0+len)*(len+1)/2;
        for(int i=0;i<len;++i)
        {
            total-=nums[i];
        }
        return total;
    }
```
