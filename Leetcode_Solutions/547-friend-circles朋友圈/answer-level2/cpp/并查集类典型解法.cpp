![image.png](https://pic.leetcode-cn.com/8f1f6780f0a234e06190a6410c389eff885f6ccd67a40c12cd70abe8d744f640-image.png)

### 解题思路
这种类似森林（多组关系，可无环）的题目，是典型的并查集（Union Search Set）类题。
先初始化集合，再合并集合（Union），再通过寻根（Search）进行相应操作，得到答案。

### 代码

```cpp
class Solution {
    int findFather(int UFS[], int idx)
    {
        if(UFS[idx] == idx) return idx;
        return findFather(UFS, UFS[idx]);
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size(), UFS[len];
        //init
        for(int i = 0; i < len; ++i)
            UFS[i] = i;
        //Union
        for(int i = 0; i < len; ++i)
            for(int j = i+1; j < len; ++j)
                if(M[i][j] == 1) //做下面优化比直接UFS[findFather(UFS, i)] = findFather(UFS, j)要节约时间
                    if(UFS[j] == j) UFS[j] = i;
                    else    if(UFS[i] == i) UFS[i] = j;
                            else UFS[findFather(UFS, i)] = findFather(UFS, j);
        //count roots
        unordered_set<int> fathers;
        for(int i = 0; i < len; ++i)
            fathers.insert(findFather(UFS, i));
        return fathers.size();
    }
};
```