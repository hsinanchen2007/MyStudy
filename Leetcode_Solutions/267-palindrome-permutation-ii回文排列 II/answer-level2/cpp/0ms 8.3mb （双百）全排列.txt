### 解题思路

0ms 8.3mb全排列

### 代码

```cpp
class Solution {
public:
    int sig[256];

    vector<string> generatePalindromes(string s) {
        int ji=0;
        for(auto &i:s){
            if(++sig[i]%2)ji++;
            else ji--;
        }
        if(ji>1)return {};
        string tmp;
        char mid=0;
        for(int i=0;i<256;i++){
            if(sig[i]==0)continue;
            if(sig[i]%2)tmp+=string(sig[i]>>1,i),mid=i;
            else tmp+=string(sig[i]>>1,i);
        }
        vector<string> ret;
        string rev(tmp.size(),' ');
        do{
            reverse_copy(tmp.begin(),tmp.end(),rev.begin());
            if(mid)ret.push_back(tmp+mid+rev);
            else ret.push_back(tmp+rev);
            }while(next_permutation(tmp.begin(),tmp.end()));
        return ret;
    }
};
```