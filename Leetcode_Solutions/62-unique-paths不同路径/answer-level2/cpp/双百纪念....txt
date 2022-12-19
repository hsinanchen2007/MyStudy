### 解题思路
![image.png](https://pic.leetcode-cn.com/c6062f9887317cde23b70ac82c889e1bbb3c60efc20239145cc8fc694786d6cd-image.png)

一维数组迭代

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<long long> temp(m, 1);
        n--;
        while (n--){
            for (int i=1; i<temp.size(); i++){
                temp[i] += temp[i-1];
            }
        }
        return temp[m-1];
    }


};
```