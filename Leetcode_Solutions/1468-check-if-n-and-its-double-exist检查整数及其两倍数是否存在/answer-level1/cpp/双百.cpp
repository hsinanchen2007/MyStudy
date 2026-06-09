### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0 && mp[arr[i]/2]!=0){
                return true;
            }
            if(mp[2*arr[i]]!=0){
                return true;
            }
            mp[arr[i]]=1;
        }
        return false;
    }
};
```