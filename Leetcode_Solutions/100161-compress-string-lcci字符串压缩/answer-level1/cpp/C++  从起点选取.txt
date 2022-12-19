一些题目，我们用人脑思考十分简单，但是落实到程序语言上，逻辑却无从写起。
所以，我们要锻炼将脑中所想转换为程序语言。
就本题来说，拿到这个题，第一反应是什么呢？我只需要锁定当前字母，然后往后找，找到几个是几个，合并下，然后再从下一个位置往下找即可。
那么程序语言如下：
```
class Solution {
public:
    string compressString(string S) {
        int idx=0,len=S.size();
        string res;
        char now;
        while(idx<len){
            now=S[idx];
            int num=1;
            idx++;
            if(idx<len&&S[idx]==now){
                while(idx<len&&S[idx]==now){
                    idx++;
                    num++;
                }
            }
            res+=now;
            res+=to_string(num);
        }
        return res.size()<S.size()?res:S;
    }
};
```
