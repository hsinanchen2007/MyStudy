### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1;i<=n/2;i++){
            if(isnz(i)==false&&isnz(n-i)==false){
                ans.push_back(i);
                ans.push_back(n-i);
                return ans;
            }
        }
        return ans;
    }
    bool isnz(int n){
        while(n!=0){
            if(n%10==0){
                return true;
            }
            n/=10;
        }
        return false;
    }
};
```