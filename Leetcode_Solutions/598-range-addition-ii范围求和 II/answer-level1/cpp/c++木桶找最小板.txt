### 解题思路

![image.png](https://pic.leetcode-cn.com/5c04f0c03f42670cfe552890dd492854c7a1b18890e47cdba39fd68e40e10545-image.png)

### 代码

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(int i=0;i<ops.size();i++)
        {
            if(m>ops[i][0]) m=ops[i][0];
            if(n>ops[i][1]) n=ops[i][1];
        }
        return m*n;
    }
};
```