### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if(count(arr.begin(),arr.end(),0)>1){
            return true;
        }
        for(auto v:arr){
            if(v!=0&&count(arr.begin(),arr.end(),v*2)){
                return true;
            }
        }
        return false;
    }
};
```