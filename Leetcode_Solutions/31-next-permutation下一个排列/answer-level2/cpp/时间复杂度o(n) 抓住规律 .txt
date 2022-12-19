### 解题思路
此处撰写解题思路
首先明确字典序有啥特点：数值大的在高位，那么就是一个比较大的数字
怎么找比某个排序更大的字段序呢
从最右边开始，找第一个不符合升序规律的数字，（因为他的右边如果从左看都是降序，考虑字典数规律，所以只有找个更大的数字放在这一位置）
只要从他右边找个刚好比他大的数字，跟他交换，然后把他右边剩下的所有数字按照升序排列，就可以了（字典序的特点）
而交换之后位置右边的数字，如果从做看是降序排列的，给头尾两两交换就好了。
时间复杂度 o(n)

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nSize=nums.size();
        if(nSize<=0)
        {
            return ;
        }
        
        int nIndex=nSize-1;
        while(nIndex>0)
        {
            if(nums[nIndex-1]<nums[nIndex])
            {
                //位置找到了
                break;
            }
            --nIndex;
        }
        --nIndex;//可能会-1
        if(nIndex>=0)
        {
                //找个刚好比nIndex对应的值大的
            for(int i=nSize-1;i>nIndex;--i)
            {
                if(nums[i]>nums[nIndex])
                {
                    int nSwamp=nums[nIndex];
                    nums[nIndex]=nums[i];
                    nums[i]=nSwamp;
                    break;
                }
            }
        }
        {
            //然后对于后面部分，按照升序排列，也就是相互调换顺序
            int nLeft=nIndex+1;
            int nRight=nSize-1;
            int nSwamp=0;
            while(nLeft<nRight)
            {
                nSwamp=nums[nLeft];
                nums[nLeft]=nums[nRight];
                nums[nRight]=nSwamp;
                ++nLeft;
                --nRight;
            }
        }
        return;
    }
};
```