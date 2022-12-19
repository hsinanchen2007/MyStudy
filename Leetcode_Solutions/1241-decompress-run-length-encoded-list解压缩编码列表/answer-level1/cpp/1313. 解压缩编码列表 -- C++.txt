### 解题思路
1.使用vector的insert在尾后迭代器前插入n个元素

### 代码

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        vector<int>::iterator iter;
        for (iter = nums.begin(); iter != nums.end(); iter += 2) {
            res.insert(res.end(), *iter, *(iter + 1));
        }
        return res;
    }
};
```