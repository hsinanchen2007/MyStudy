### 解题思路
见注释

### 代码

```cpp
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
/*
|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j| 
令 i > j(i j 可互换，顺序无所谓)
有四种情况：
1.  arr1[i] - arr1[j] + arr2[i] - arr2[j] + i - j;
2.  arr1[i] - arr1[j] - arr2[i] + arr2[j] + i - j;
1.  -arr1[i] + arr1[j] + arr2[i] - arr2[j] + i - j;
1.  -arr1[i] + arr1[j] - arr2[i] + arr2[j] + i - j;
*/
    int pre[4] = {0};
    pre[0] = -arr1[0] - arr2[0];
    pre[1] = -arr1[0] + arr2[0] ;
    pre[2] = +arr1[0] - arr2[0] ;
    pre[3] = +arr1[0] + arr2[0] ;
    int maxnum = 0;
    for(int i = 1;i < arr1.size();i++)
    {
        maxnum = max(maxnum,arr1[i] + arr2[i] + i + pre[0]);
        pre[0] = max( -arr1[i] - arr2[i] - i,pre[0]);

        maxnum = max(maxnum,arr1[i] - arr2[i] + i + pre[1]);
        pre[1] = max( -arr1[i] + arr2[i] - i,pre[1]);

        maxnum = max(maxnum,-arr1[i] + arr2[i] + i + pre[2]);
        pre[2] = max( +arr1[i] - arr2[i] - i,pre[2]);

        maxnum = max(maxnum,-arr1[i] - arr2[i] + i + pre[3]);
        pre[3] = max( +arr1[i] + arr2[i] - i,pre[3]);
    }

    return maxnum;

    }
};
```