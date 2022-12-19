### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> count;
        for(int i = 0; i < arr.size(); i++){
            count[arr[i]]++;
        }
        set<int> cmp;
        for(auto i = count.begin(); i != count.end(); i++){
            if(cmp.find(i -> second) != cmp.end()){
                return false;
            }
            cmp.insert(i -> second);
        }
        return true;
    }
};
```