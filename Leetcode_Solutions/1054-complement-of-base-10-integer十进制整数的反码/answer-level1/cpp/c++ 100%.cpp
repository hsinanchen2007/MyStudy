```cpp
class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)return 1;
        int res=0;
        vector<int> vec;
        while(N){
            if(N%2==0)vec.push_back(1);
            else vec.push_back(0);
            N/=2;
        }
        reverse(vec.begin(),vec.end());
        int tmp=1;
        while(vec.size()>0){
            res+=vec.back()*tmp;
            vec.pop_back();
            tmp*=2;
        }
        return res;
    }
};
```