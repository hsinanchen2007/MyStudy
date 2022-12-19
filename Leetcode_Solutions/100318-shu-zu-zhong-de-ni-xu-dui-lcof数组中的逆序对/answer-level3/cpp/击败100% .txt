### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/9bc029bdefe29c44e6684c4dfc6097ccaca08418a63afd3e8af54e6819ea2374-image.png)

### 代码

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> copy(nums);
        int size = nums.size();
        if(size == 0 || size == 1) return 0;
        return help(nums,copy,0,size - 1);
    }
    int  help(vector<int>& nums,vector<int>& copy,int start,int end)
    {
        if(start == end)
        {
            copy[start] = nums[start];
            return 0;
        }
        int len = (end - start) / 2;
        int left = help(nums,copy,start,start + len);
        int right = help(nums,copy,start + len + 1,end);
        
        int i = start + len;
        int j = end;
        int index = end;

        int count = 0;

        while(i >= start && j >= start + len + 1)
        {
            if(nums[i] > nums[j])
            {
                copy[index--] = nums[i--];
                count += j - start - len;
            }
            else
            {
                copy[index--] = nums[j--];
            }
        }
        while(i >= start)
        {
            copy[index--] = nums[i--];
        }
        while(j >= start + len + 1)
        {
            copy[index--] = nums[j--];
        }
        
         //把copy后的数组 回到原数组
        for(int i = start; i <= end; i++) {
            nums[i] = copy[i];
        }
        return left + right + count;
    }
};
```