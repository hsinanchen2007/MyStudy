```cpp [cpp]
class Solution {
public:
    string countAndSay(int n) {
        string temp("1");
        string res("1");
        for(n;n>1;--n){
            res="";
            int count(0);
            //哨兵
            temp+="#";
            for(int i=0;i<temp.size()-1;++i){
                ++count;
                if(temp[i]!=temp[i+1]){
                    res+=to_string(count);
                    res+=temp[i];
                    count=0;
                }
            }
            temp=res;
        }
        return res;
    }
};
```
