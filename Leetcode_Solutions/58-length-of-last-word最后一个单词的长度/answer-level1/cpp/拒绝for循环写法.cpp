### 解题思路

本人菜鸟
我这效率不怎么样，写多了各种for各种if有点厌烦，
尝试了更加简便的写法。
利用istringstream的优势，可以将字符串的空格自动去除，
剩下非' '的字符，存在一个vector里，剩下就是判断vector即可。



### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {

        istringstream strcin(s);
        string ss;
        vector<string> vs;
        while(strcin >> ss) vs.push_back(ss);

        if(vs.empty())  return 0;
        return vs[vs.size()-1].size();
    }
};
```