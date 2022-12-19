### 解题思路
可以理解为求前缀和，当字符为“L"时sum+1, 当字符为“R”时，sum-1；当sum=0是说明前边L和R的数量现同，则可以进行依次分割，重复进行上述操作，就可以得到切割数。

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int sum=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                sum+=1;
            }else{
                sum+=-1;
            }
            if(sum==0){
                ans++;
            }
        }
        return ans;
    }
};
```