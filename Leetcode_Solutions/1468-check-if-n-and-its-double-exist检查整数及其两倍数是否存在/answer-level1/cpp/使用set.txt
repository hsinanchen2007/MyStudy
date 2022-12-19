### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> mp1;// 保存自身
        set<int> mp2;   //保存自身的两倍

        for(int i=0; i<arr.size(); i++){
            if(mp2.find(arr[i]) == mp2.end() && mp1.find(arr[i]*2) == mp1.end()){
                mp2.insert(arr[i]*2);
                mp1.insert(arr[i]);
                continue;
            }
            else return true;

        }
        return false;
    }
};
```