### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:               //这题需要注意的是string tmp=s[i]+s[i+1]+s[i+2]有点不是我们预期的答案，有点出乎意料，不是常规的  ，所以我换成string自带的求子串的函数substr（）
    string freqAlphabets(string s) {
        if(s.size()==0) return "";
        unordered_map<string,string>umaps;//这必须使用string
        string tmp="",res="";
         umaps["1"]='a';
         umaps["2"]='b';
         umaps["3"]='c';
         umaps["4"]='d';
         umaps["5"]='e';
         umaps["6"]='f';
         umaps["7"]='g';
         umaps["8"]='h';
         umaps["9"]='i';
         umaps["10#"]='j';
         umaps["11#"]='k';
         umaps["12#"]='l';
         umaps["13#"]='m';
         umaps["14#"]='n'; 
         umaps["15#"]='o';
         umaps["16#"]='p';
         umaps["17#"]='q';
         umaps["18#"]='r';
         umaps["19#"]='s';
         umaps["20#"]='t';
         umaps["21#"]='u';
         umaps["22#"]='v';
         umaps["23#"]='w';
         umaps["24#"]='x';
         umaps["25#"]='y';
         umaps["26#"]='z';
        for(int i=0;i<s.size();){
            if (i+2 < s.size() && s[i + 2] == '#') {
                tmp=s.substr(i,3);
                res+=umaps[tmp];
                tmp="";
                i+=3;
            }
            else{
                tmp=s[i];
                res+=umaps[tmp];        //否则答案始终为空
                i++;
                tmp="";
            } 
        }
        return res;
    }
};
```