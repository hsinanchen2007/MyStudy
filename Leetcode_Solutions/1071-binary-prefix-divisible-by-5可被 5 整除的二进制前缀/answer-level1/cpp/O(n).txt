### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> v;
        int t=0;
        for(int i=0;i<A.size();i++){
            t*=2;
            t+=A[i];
            if(t%5==0){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
            t%=5;
        }
        return v;
    }
};
```