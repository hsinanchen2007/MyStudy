### 解题思路
哈希表统计次数，然后根据题目数组长度的约束条件

### 代码

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        if(arr.size() == 0)
        {
            return 0;
        }
        unordered_map<int,int> map;
       
        for(int i = 0;i < arr.size();i++)
        {
            map[arr[i]]++;
        }
        for(int i = 500;i >= 1;i--)
        {
            if(map[i] == i)
            {
                return i;
            }
        }
        return -1;
    }
};
```