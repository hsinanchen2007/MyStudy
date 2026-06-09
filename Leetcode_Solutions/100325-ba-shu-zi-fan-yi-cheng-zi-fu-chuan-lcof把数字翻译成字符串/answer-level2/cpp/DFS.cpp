```
class Solution {
public:
    int translateNum(int num) {
        int ans=0;
        lalala(to_string(num),ans);
        return ans;
    }

    void lalala(const string& num,int& ans){
        if(num.size()==0){
            ++ans;
            return;
        }
        lalala(num.substr(1),ans);
        if(num.size()>=2&&num[0]!='0'&&stoi(num.substr(0,2))<=25){
            lalala(num.substr(2),ans);
        }
    }
};
```
