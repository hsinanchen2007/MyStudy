```cpp
class Solution {
public:
    char converse(int x){
        return x+'A';
    }
    string convertToTitle(int n) {
        string res="";
        while(n>0){
            res+=converse((n-1)%26);
            n=(n-1)/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```