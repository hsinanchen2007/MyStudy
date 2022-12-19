
```cpp
class Solution {
public:
    bool zichushu(int x){
        int tmp=x;
        int ans;
        while(tmp){
            ans=tmp%10;
            if(ans==0||x%ans!=0)return false;
            tmp/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;++i){
            if(zichushu(i))res.push_back(i);
        }
        return res;
    }
};
```