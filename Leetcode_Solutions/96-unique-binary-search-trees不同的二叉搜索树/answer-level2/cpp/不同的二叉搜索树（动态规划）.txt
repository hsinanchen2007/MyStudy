### 解题思路
此处撰写解题思路
1、第一个for循环，为计算每个数i∈(1--n)可以形成的二叉搜索树个数。
2、第二个for循环，为计算数i可以形成的二叉搜索树。
（1）其可以分解为0,i-1; 1,i-2; 2,i-3; .. ;k,l; .. i-2,2;i-1,0对
	其中，k,l分别代表左子树和右子树的个数。k=0时，左子树为空，则个数为1，k*l即为i对应的二叉搜索树个数。

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
			return 1;//set val as leetcode
        
		int *result = new int[n+1];
		memset(result, 0, sizeof(int)*(n + 1));
		result[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
				result[i] = result[i] + result[j] * result[i - j - 1];
		}
		int r = result[n];
		delete []result;
		return r;
    }
};
```