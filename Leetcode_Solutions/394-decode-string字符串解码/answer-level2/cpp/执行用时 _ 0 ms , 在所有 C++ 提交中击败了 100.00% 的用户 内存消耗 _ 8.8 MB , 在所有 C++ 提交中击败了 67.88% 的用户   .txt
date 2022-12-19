### 解题思路
此题的核心思路是: 要先思考：栈应存储什么元素，何时进栈、出栈
```
    以下用a2[b]举例子：
    1 当遇到'['，把'['和与之匹配的']'之间的字母需要重复的次数和'['之前的字符进栈，本例中进栈{2,a}
    2 当遇到']'，代码中的字符串res即：b,就是要重复的字母，此时出栈之前进栈的{2,a}，res变成a+2*b = abb
    3 部分注意事项看注释即可
```
### 代码
```cpp
class Solution {
public:
    typedef pair<int,string> pis;
    //将字符串str重复times次
    string repeat(const string& str, int times) {
        string retString = "";
        for(int i = 0; i < times; ++i) retString += str;
        return retString;
    }
    //先思考：栈应存储什么元素，何时进栈、出栈
    string decodeString(string& s) {
        int repeatTims = 0;
        string res = "";
        vector<pis> vecStack;   //用vector代替stack，更高效，因为stack底层可以是vector
        for(auto i : s) {
            if('0'<=i && i<='9') repeatTims = (repeatTims*10)+(i-'0');  //计算字符串需要重复的次数
            else if(i == '[') {
                vecStack.push_back({repeatTims,res});
                //进栈后要更新res和repeatTimes，并不担心最后返回的res为空，因为之前更新的res在遇到'['又会被进栈
                //不懂这问题的可以手动模拟一下这个样例：3[a]2[bc]ef
                res = "";
                repeatTims = 0;
            }
            else if(i == ']') {
                pis tmp = vecStack[vecStack.size()-1];
                vecStack.pop_back();
                res = tmp.second + (tmp.first==0 ? "" : repeat(res, tmp.first));
            }
            else res += i;
        }
        return res;
    }
};
```