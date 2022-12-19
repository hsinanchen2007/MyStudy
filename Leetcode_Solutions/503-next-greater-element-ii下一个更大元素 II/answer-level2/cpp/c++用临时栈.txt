### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>result(nums.size(),-1);  //用来存储结果
        stack<int>stack_temp;  //定义一个临时栈
        int n=nums.size();
        for(int i=0;i<nums.size()*2;i++)
        {
            int j= i%n;//遍历2遍必然能找到所有的情况
            while(!stack_temp.empty()&&(nums[j]>nums[stack_temp.top()]))
            {
                result[stack_temp.top()]=nums[j];
                stack_temp.pop();
            }
            if(i<n)
            {
                //说明没有循环过来
                stack_temp.push(j);
            }
        }
        return result;
    }
};
```其实关键在于第二次扫描如何控制变量