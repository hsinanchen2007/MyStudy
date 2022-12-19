### 解题思路
此处撰写解题思路
?????
### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int temp=target;
        for(auto i:matrix){
            for(auto j:i){
                if(!(temp^j)) return true;
            }
        }
        return false;
    }
};
```