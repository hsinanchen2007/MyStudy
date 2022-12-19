### 思路
1. 单调栈
2. 正向遍历，单调递增栈，找出自始至终没有出栈的最大索引 `l`
3. 反向遍历，单调递减栈，找出自始至终没有出栈的最小索引 `r`
4. 中间就是需要排序的最小子数组

### 答题
```C++ []
    int findUnsortedSubarray(vector<int>& nums)
    {
        stack<int> st;
        int l = nums.size() - 1;
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        return (r > l) ? r - l + 1 : 0;
    }
```

### 其他
```c++ []
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0;
        int r = 0;
        int minNum = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            l = (nums[i] > minNum) ? i : l;
            minNum = min(minNum, nums[i]);
        }
        int maxNum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            r = (nums[i] < maxNum) ? i : r;
            maxNum = max(maxNum, nums[i]);
        }
        return (r > l) ? r - l + 1 : 0;
    }
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

