```cpp
class Solution {
public:
    int maximum69Number (int num) {
        vector<int> tmp;
        while(num){
            tmp.push_back(num%10);
            num/=10;
        }
        for(int i=tmp.size()-1;i>=0;--i){
            if(tmp[i]==6){
                tmp[i]=9;
                break;
            }
        }
        int res=0;
        int k=1;
        for(int i=0;i<tmp.size();++i){
            res+=tmp[i]*k;
            k*=10;
        }
        return res;
    }
};
```