### 解题思路
* 详看[官方思路](https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/)

### 代码

```cpp
class Solution {
public:
    // 题目保证多数元素存在
    // Boyer-Moore 投票算法
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = -1;

        for(int i: nums) {
            if(candidate == i) {
                count++;
            }
            else if(--count < 0){
                candidate = i;
                count = 1;
            }
        }
        return candidate;
    }
};
```
![1.png](https://pic.leetcode-cn.com/8c61d9b4fa2f54373a7242f391e808731455bf43bba0c34c1f1d0341a204df27-1.png)

```cpp
    // 哈希
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;

        int maj = -1;
        int count = 0;
        for(int n: nums) {
            counts[n]++;
            if(counts[n] > count) {
                maj = n;
                count = counts[n];
            }
        }
        return maj;
    }
```
![2.png](https://pic.leetcode-cn.com/7863307ae9d01f1d6783a661492d5cfa24e50b72d1f52676f0dc03a3bf98ce2f-2.png)
