```c++
class Solution {
public:
    bool isHave(int a){
        string base="0125698",str="2569";
        bool isStr=false;
        for (auto s: to_string(a)){
            if (base.find(s)==base.npos)
                return false;
            if (str.find(s)!=str.npos)
                isStr=true;
        }
        return isStr;
    }
    int rotatedDigits(int N) {
        int cnt=0;
        for (int t=1;t<=N;t++){
            if (isHave(t))
                cnt++;
        }
        return cnt;
        
    }
};
```
