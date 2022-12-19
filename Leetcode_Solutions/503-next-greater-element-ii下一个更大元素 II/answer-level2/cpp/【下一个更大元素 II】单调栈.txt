### 执行时间
![图片.png](https://pic.leetcode-cn.com/ae29ee37dec1a109ee99a875a9fc47a5d213e6c634ef1ad6e30cb241fc4433b0-%E5%9B%BE%E7%89%87.png)

### 思路
1. 使用单调栈
2. 因为是循环，跑两圈总行了吧
3. 在栈里没弹出来的是数组中最大的
4. 初始化的时候直接 -1 ，就不用特殊处理他了

### 答题
```C++
vector<int> nextGreaterElements(vector<int>& nums) 
{
    vector<int> ans(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size() * 2; i++)
    {
        int j = i % nums.size();

        while (!st.empty() && nums[st.top()] < nums[j])
        {
            ans[st.top()] = j;
            st.pop();
        }
        st.push(j);
    }

    for (auto& n : ans)
    {
        n = (n == -1) ? -1 : nums[n];
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

