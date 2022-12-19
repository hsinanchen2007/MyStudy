### 解题思路
执行用时 :40 ms, 在所有 C++ 提交中击败了96.80% 的用户
内存消耗 :10 MB, 在所有 C++ 提交中击败了100.00%的用户
[137题的题解](https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetcode/)
我自己折腾了一个137题的题解也挺快的，137可以80%是哈希表的。

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        uint32_t once = 0, twice = 0; 
        for (auto & el: nums){
            once = ~twice & (once ^ el);
            twice = ~once & (twice ^ el);
        }
        return once;
    }
};
```

哈希表的快速解法

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<unint32_t, unint8_t>hmap;
        for (auto &el:nums){
            hmap[el]++;
            if(hmap[el] == 3)hmap.erase(el);
        }
        return hmap.begin()->first;
    }
};
```