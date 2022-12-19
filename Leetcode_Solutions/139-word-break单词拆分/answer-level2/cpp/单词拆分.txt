### 解题思路
此处撰写解题思路
这个题困扰了我一天半，究其原因，C++内置函数知道的太少，这里用到了find(begin, end, item)函数
思考一下这个题吧，以str(begin, end)来表示str的子字符串，从前往后遍历，有多少种呢？
end=1, begin=0;
end=2, begin=0/1;
end=3, begin=0/1/2;
...
end=n-1, begin=0/1/.../n-2;
一共是(n-1)n/2种，遍历一遍是O(n^2)的时间复杂度
这么多种可能的子字符串，逐次的去判断它们是否与字典中的某个字符串相同，如果相同了，就在end的位置标记相同(true)，end的位置一定在begin之后（begin<end），那么要查询str(begin, end)，begin前面的位置一定要是true才行，意味着已经寻到了一个或者一些匹配字典的子字符串，那么就要记录是否寻得的状态。
既然要寻找，最开始的状态就要是true，也就是dp[0]=true，其他位为false，一旦寻得，end为的状态变为true，继续往下寻找，为了避免漏掉某些情况，每次的begin都是从0开始的。

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() ||wordDict.empty()) return false;
        int n=s.size();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for(int end=1; end<=n; end++){
            for(int begin=0; begin<end; begin++){
                if(dp[begin] && find(wordDict.begin(), wordDict.end(), 
                s.substr(begin, end-begin))!=wordDict.end()){
                    dp[end]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```