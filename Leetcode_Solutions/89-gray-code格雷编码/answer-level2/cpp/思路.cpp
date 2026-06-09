### 解题思路
就是在n-1的基础上逆着把n-1的所有结果加上2^(n - 1)


### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int>vec;
		vec.push_back(0);
		for (int i = 1; i <= n; ++i)
		{
			int nCount = vec.size();
			for (int j = nCount - 1; j >= 0; --j)
			{
				vec.push_back(vec[j] + (int)pow(2, i - 1));
			}
		}
		return vec;
    }
};
```
###结果
![捕获.PNG](https://pic.leetcode-cn.com/d8fd232b4c233e0af875b7cbdf39595a88a3d31b013d2248a68bc569c8f20350-%E6%8D%95%E8%8E%B7.PNG)