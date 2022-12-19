思路：一维dp 用map维护之前出现过的最大值 O(nlogn)
![捕获.PNG](https://pic.leetcode-cn.com/b8138216c3b88be5fca025316f942ddc34c1e7bd9c23a78d5110e24c0fbf63d3-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    map<int,int>m;
    int ans = 0;
    int longestSubsequence(vector<int>& arr, int difference) {
        for(auto x: arr)
        {
            int dp = 1;
            if (m.count(x-difference))  dp = m[x-difference] + 1;
            ans = max(dp, ans);
            m[x] = max(m.count(x)? m[x]:1, dp);
        }
        return ans;
    }
};
```

更新：没想到还有这么多的提升方法，代码长度、时间复杂度等等都提升了。感谢评论和其他题解带给我的新思路。
![image.png](https://pic.leetcode-cn.com/640bbc04822f3a00cc5080d4430553b25f2983058e85234a1fa5360a629231fa-image.png)

```
class Solution {
public:
    unordered_map<int,int>m;
    int ans = 0;
    int longestSubsequence(vector<int>& arr, int difference) {
        for(auto x: arr) ans = max(ans,m[x] = m[x-difference] + 1);
        return ans;
    }
};
```
