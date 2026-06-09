### 解题思路
![1.png](https://pic.leetcode-cn.com/18d82ddef5f4c38ddfdd5fc4b6b085292a67b35699711e847e57c646b681dd5a-1.png)

### 代码
```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int tmp = max;
            if (arr[i] > max)max = arr[i];
            arr[i] = tmp;
        }
        return arr;
    }
};
```