### 解题思路
将字符串拆成字串，逐段比较即可，记录头尾的指针

### 代码

```cpp
class Solution {
public:
    bool isStretchy(string target, string basic){
        int len1=target.length();
        int len2=basic.length();

        if(len1<len2) return false;

        if(basic[0]!=target[0]) return false;
        int s1=0,s2=0,e1=0,e2=0;
        
        while(s1<len1 && s2<len2){

            while(target[e1]==target[s1] && e1<len1) e1++;
            while(basic[e2]==basic[s2] && e2<len2) e2++;
            if(e1-s1<e2-s2) return false;
            if(e1-s1>e2-s2 && e1-s1<3) return false;
            s1=e1;
            s2=e2;
            if(target[e1]!=basic[e2]) return false;
        }
        return true;
    }
    int expressiveWords(string S, vector<string>& words) {
        int count=0;
        for(auto str:words){
            if(isStretchy(S, str)) count++;
        }
        return count;
    }
};
```