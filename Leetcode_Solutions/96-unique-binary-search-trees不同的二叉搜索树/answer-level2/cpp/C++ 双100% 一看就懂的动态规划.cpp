##### 解题思路
其实这题，很像**高中化学里面数同分异构体**的题目。
但有一个不同，在于有一个分支可以有0个数字。
所以，只要用一个算出两边分支的“异构数”，相乘，就可以得到答案。
**TIPS**：此处可以利用对称性，将循环的次数减半。
![微信图片_20200327010308.png](https://pic.leetcode-cn.com/4145a9fbb600c708e3330ac9516d0d547c913a84c7645ed9c4fd6d4ea7be5ff6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200327010308.png)

##### 代码

```cpp
class Solution {
public:
int numTrees(int n) {
	vector<int> v(n+1,0);//这样之后相当于有了空间，不用再pushback,直接赋值就好。
	v[0] = 1;
	v[1] = 1;
	if (n <= 1)
		return v[n];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i/2; j++)
			v[i] += 2 * (v[j] * v[i - j - 1]);//由对称性，可以直接用乘以2倍。
		if (i % 2 == 1)
			v[i] += v[i / 2] * v[i / 2];//如果i是奇数的话，需要加上中间的v[i / 2]相乘。
	}
	return v[n];
}
};
```