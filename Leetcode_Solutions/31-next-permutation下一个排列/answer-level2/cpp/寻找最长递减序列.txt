### 解题思路
先讨论最简单的两个情况：
1整个序列递增，则将序列反转。
2倒数第二个数小于最后一个数，swap两个元素即可
复杂的情况：
例：1,4,7,5,3
序列从第3个元素开始递减，这时需要找到这递减序列中比第2个元素大的最小的元素（5），对调两个元素，
序列变为：1,5,7,4,3，这时候将第2个元素之后的序列反转，得到结果：1,5,3,4,7。



### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
        return;
        int k;
        int i=nums.size()-1;
        int j=i-1;
        while(j>=0)
        {
            if(nums[j]>=nums[j+1])
            j--;
            else 
            {
              int k=i;
              while(k>j)
              {
                  if(nums[k]>nums[j])
                  {
                   swap(nums[k],nums[j]);
                      reverse(nums,j+1,i);
                      return;
                  }
                  k--;
              }  
            }

        }
        reverse(nums,0,i);
        return;
    }
    void reverse(vector<int>& nums,int begin,int end)
    {
        if(end==begin) return;
        for(int m=0;m<=(end-begin)/2;m++)
       swap(nums[m+begin],nums[end-m]);
    }
};
```