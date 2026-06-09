

如下
```
class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        if (s == "") return true;
        queue<char> ss;
        for(auto it=s.begin();it!=s.end();it++){
            ss.push(*it);
        }
        for(auto it=t.begin();it!=t.end();it++){
            if(*it == ss.front()) ss.pop();
            if(ss.empty()) return true;        //<-不可以放在上一句前面！
        }
        return false;
    }
};

```
这道题明明是队列，不知道为什么leetcode标记在栈里面？ 就一点卡了我很久很久，就是标红位置绝对不可以放在上一句的前面！！！否则，如果s和t最后一个相同的char恰好在它们的末尾，这种情况就判断不出来了！