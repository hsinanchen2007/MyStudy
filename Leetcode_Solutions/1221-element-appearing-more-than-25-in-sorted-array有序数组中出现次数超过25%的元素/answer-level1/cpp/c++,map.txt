### 解题思路
直接将array中的数值送入map中进行计数然后返回超过百分之25的键值对应的键

### 代码

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count=0;
        int n=arr.size();
        map<int,int> mapa;
        for(auto x:arr){
            mapa[x]+=1;
        }
        for(auto x:arr){
            if(mapa[x]*4>n){
                return x;
            }
        }
        return -1;
        
    }
};
```