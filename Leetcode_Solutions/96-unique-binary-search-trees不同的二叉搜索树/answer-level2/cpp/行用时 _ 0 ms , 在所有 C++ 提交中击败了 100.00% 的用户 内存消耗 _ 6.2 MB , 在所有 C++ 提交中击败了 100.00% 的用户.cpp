### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int a[300][300];
    int treeNum(int l, int r){
        int sum = 0;
        if(r<=l) return 1;
        if(a[l][r] != 0) return a[l][r];
        for(int t=l; t<=r; t++){
            int lnum = treeNum(l, t-1);
            int rnum = treeNum(t+1, r);
            sum += lnum*rnum;
        }
        if(a[l][r] == 0) a[l][r] = sum;
        return sum;
    }
    int numTrees(int n) {
        memset(a, 0, sizeof(a));
        if(n == 0) return 0;
        return treeNum(1, n);
    }
};
```