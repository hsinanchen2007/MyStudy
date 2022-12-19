**
# 题意：
其实很简单，就是要先数一数Q,W,E,R各自出现的次数，然后肯定是修改哪些出现次数多于平均数的字母，题目的意思是，要找到一个子串，将这个串修改，当然是将那些次数多了的字母改成那些次数少了的字母，然后找到一个最短的子串，于是很符合滑动窗口的思想。

# 代码：
```
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int averge = n/4;
        map<char,int>hash;
        map<char,int>window;
        map<char,int>need;
        for(auto&c :s)//记录个字母出现次数
            hash[c]++;
        for(auto&p : hash){
            if(p.second>averge)//大于平均值的，肯定是要修改的，因此加入need里，
                need[p.first] = p.second-averge;//次数修改为多于平均值的次数
        }
        if(need.size() == 0)
            return 0;
        int l = 0, r = 0;
        int match = 0;
        int res = n;//取最大
        while(r<n){
            char c = s[r];
            if(need.find(c) != need.end()){//符合一定条件
                window[c]++;
                if(window[c] == need[c])//对应次数符合后，匹配数++
                    match++;
            }
            r++;
            while(match == need.size()){//匹配数与need的大小相等，表明当前窗口已经包括所有需要修改的字符了
                res = min(res,r-l);//更新窗口大小
                char c2 = s[l];
                if(need.find(c2) != need.end()){//破坏条件
                    window[c2]--;
                    if(window[c2] < need[c2])
                        match--;
                }
                l++;
            }
        }
        return res;
    }
};

# 代码总结以及类似的leetcode的题
：请看博客：https://blog.csdn.net/LLM1602/article/details/105119203


