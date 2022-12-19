第一个 for 循环是给 match 数组做标记，第二个 for 循环 是找出 match 数组中最长的连续 1 的长度，即为答案。
![截屏2020-03-07下午3.33.41.png](https://pic.leetcode-cn.com/fc20a14e338db32cc418e5f2f0bdae14ad50bce15138ed30fb9c78aec0632332-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8B%E5%8D%883.33.41.png)

``` cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> schr; // 左括号的下标
        vector<int> match(s.size(), 0); // 匹配标为 1
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                schr.push(i);
            } else if(!schr.empty()) {
                match[schr.top()] = 1;
                match[i] = 1;
                schr.pop();
            }
        }
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < match.size(); i++) {
            if(match[i] == 1) cnt++;
            else cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```
