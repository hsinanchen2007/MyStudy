### 解题思路


### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n,false);
        for(int i = 2;i * i < n;i++){
            if(!vec[i]){
                for(int j = i + i;j < n;j += i){
                    vec[j] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 2;i < n;i++)
            if(!vec[i]) ans++;
        return ans; 
    }
};
```