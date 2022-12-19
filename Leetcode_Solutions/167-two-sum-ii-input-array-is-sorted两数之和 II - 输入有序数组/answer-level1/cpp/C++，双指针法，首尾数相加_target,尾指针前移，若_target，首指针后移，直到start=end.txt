### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i;int j;
        int len=numbers.size();
        int  start=0;int end=len-1;
        while(start<end)
        {
            if(numbers[start]+numbers[end]==target)
              return {start+1,end+1};
              if(numbers[start]+numbers[end]>target)   end--;
              if(numbers[start]+numbers[end]<target)    start++;
        }
         return {start+1,end+1};
    }
};
```