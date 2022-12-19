### 解题思路
![SharedScreenshot.jpg](https://pic.leetcode-cn.com/9e28498d209559477a12a1f0f7a9679bf302c0adf5b4d9af701b55fe03c02269-SharedScreenshot.jpg)
从1到n，挨个做根节点。
根节点左边的数做左子树，右边的树做右子树。
两种子树的可能相乘得到该根节点的子树总和
### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int result[n+1];
        memset(result,0,sizeof(result));
        result[0]=1;
        result[1]=1;
        result[2]=2;
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                result[i]+=result[j-1]*result[i-j];
        }
        return result[n];
    }
};
```