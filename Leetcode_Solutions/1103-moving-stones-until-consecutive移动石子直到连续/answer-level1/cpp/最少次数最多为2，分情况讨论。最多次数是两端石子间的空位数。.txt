先将a，b，c左中右排好序，左边位置为x,中间位置为y，右边位置为z。
1、最少次数：
1）我们可以将左边的石子移到中间石子的左边一格，右边的石子移到中间石子的右边一格。
因此我们找到了一个只要移2次的方法，所以最少次数最多为2.
2）具体情况分情况讨论。

2、最多次数：
1）我们可以将左边的石子每次向右移一格直到移到中间石子的左边一格，右边的石子每次向左移一格直到移到中间石子的右边一格。
因此我们找到一个可以移动`z - x - 2`次的方法，所以最多次数至少为`z - x - 2`。
2）由于每次移动满足`x < k < z`,不管k原来的位置是x还是z，都有`z'-x' < z-x`（z'、x'分别为z和x的新位置），即新的左右位置距离比原左右位置距离至少小了1，所以最多次数至多为`z - x - 2`。
3）综上，最多次数为`z - x - 2`。

```C++ []
class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> v;
        vector<int> tmp={a,b,c};
        sort(tmp.begin(),tmp.end());
        if(tmp[2]-tmp[0]==2)
            v.push_back(0);
		else if ((tmp[1] - tmp[0] < 3) || (tmp[2] - tmp[1] < 3))
			v.push_back(1);
		else
			v.push_back(2);
		v.push_back(tmp[2] - tmp[0] - 2);
		return v;
	}
};
```
