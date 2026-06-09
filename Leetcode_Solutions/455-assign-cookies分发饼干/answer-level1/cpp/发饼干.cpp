### 解题思路
利用贪心算法的思想，将俩个数组进行从小到大排序；按照把最小的饼干分发给需求最小的小孩的思想。首先，将俩个数组进行排序，当小孩或者饼干同时满足条件时，从最小的那个数开始，如果该饼干可以满足小孩的需求则将俩个数组同时向后推，同时result+1.当饼干不满足小孩需求时，饼干的数组加一，下一个更大的饼干与小孩进行匹配，观察是否满足小孩需求，直到全部遍历完成。

### 代码

```cpp
class Solution {
public:
     int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int gi = 0;
        int result = 0;
        while (gi < g.size() && result < s.size()) {
            if (s[result] >= g[gi]) {
                result ++;  
                gi++;
            } else {
                gi++;
            }
        }
        return result;
    }
};
```