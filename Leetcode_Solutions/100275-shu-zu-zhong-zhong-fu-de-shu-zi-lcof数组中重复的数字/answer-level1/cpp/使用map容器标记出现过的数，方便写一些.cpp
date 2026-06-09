### 解题思路
此处撰写解题思路
使用map容器标记出现过的数，方便写一些
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> q;
        for(auto iter = nums.begin();iter!=nums.end();iter++){
            if(q[*iter] != 1){
                q[*iter] = 1;
            }
            else{
                return *iter;
            }
        }
        return -1;
    }
};
```