### 解题思路
这道题目其实和单调栈很接近，可以使用单调栈的方法来解决。
题目的描述中可以看到判定条件为：
```
[i < j < k] -> [ai < ak < aj]
```
从这里可以看到，对于i而言，只需要找到一个比前面都小的即可。
对于j和k而言，正好符合单调栈的使用情形。
举个例子：
示例3：输入[-1,3,2,0] 输出true；
我们从右往左搜寻，原因在于，只要j和k解决了，i只需要简单的判断即可。
我们从最右边开始遍历。
1、输入为0，压0入栈；
2、输入为2，判定2和栈顶的元素的大小。
- 2的下标为2，0的下标为3，满足[2 < 3] -> [a3 < a2];

3、此时只需要搜寻比这两个都小的i即可，即找到比a3小的即可；
4、输入-1，发现其比ak小，即返回true。

这里有个坑需要注意下：
用来存储中间ak的数初始化应该为**INT_MIN**，不然会出现解答错误的情况
### 代码

```cpp
class Solution {
public:
    //使用单调栈来求解
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        stack<int> stk;
        //这个地方也有问题
        int max_num = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i] < max_num) return true;
            while(!stk.empty() && nums[i] > stk.top())
            {
                max_num = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
```