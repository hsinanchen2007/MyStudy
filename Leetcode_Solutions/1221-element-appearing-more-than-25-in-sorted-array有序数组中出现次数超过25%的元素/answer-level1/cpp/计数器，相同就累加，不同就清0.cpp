### 解题思路


### 代码

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans=-1,sz=arr.size(),cnt=0;
        for(register int i=0;i<sz;++i){
            if(ans==arr[i])cnt++;
            else
                cnt=0,ans=arr[i];
            if(cnt==sz/4)return ans;
        }
        return ans;
    }
};
```