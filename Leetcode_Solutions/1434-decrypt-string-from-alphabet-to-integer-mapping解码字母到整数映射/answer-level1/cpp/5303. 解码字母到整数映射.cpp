### 解题思路
1.构造映射关系的dict。
2.遍历并分割总串，并替换出相应返回的字符，依次累积起来。这里维护一个buff队列保存待确认状态的数字。
    根据遍历的当前字符，以及buff的内容，共分三种状态：
    1.当前是#且buff两位数 -> 整体替换
    2.当前不是#且已经buff两位 -> 取出队首单独替换
    3.当前不是#且未buff到两位 -> buff该数字
3.最后遍历结束，清空buff，返回结果

#### 可优化的点
1.可以尝试用hash map会不会更快
2.ostringstream应该是比较浪费时间的，用纯c的char*会好一点吧
3.构造dict可以用单例模式吧，多次调用就得多次初始化也会浪费时间，不知道后台系统是不是能支持的，，，


### 代码

```cpp

#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

unordered_map<string, string> dict;


class Solution {
public:
    string freqAlphabets(string s) {
        map<string, string> dict;
        ostringstream oss;
        for(int i=0; i<9; ++i){
            oss.str("");
            oss<<(char)('1'+i);
            dict[oss.str()] = (char)('a'+i);
        }
        for(int i=9; i<26; i++){
            oss.str("");
            oss<<i+1<<"#";
            dict[oss.str()] = (char)('a'+i);
        }
//        for (auto it = dict.begin(); it!= dict.end(); ++it)
//            cout<<it->first<<"|"<<it->second<<endl;

        queue<string> vec;
        string ret;
        //cout<<s<<endl;
        for(int i = 0; i<s.size(); ++i){
            oss.str("");
            oss<<s[i];
            string ch = oss.str();
            //cout<<ch<<endl;
            if (ch == "#"){
                //cout<<"a"<<endl;
                string key = "";
                key += vec.front();
                vec.pop();
                key += vec.front();
                vec.pop();
                key+=ch;
                ret += dict[key];
            } else if (vec.size() <= 1){
                //cout<<"b"<<endl;
                vec.push(ch);
            } else {
                //cout<<"c"<<endl;
                vec.push(ch);
                ret += dict[vec.front()];
                vec.pop();
            }
        }
        while(!vec.empty()){
            ret += dict[vec.front()];
            vec.pop();
        }
        return ret;
    }
};
```