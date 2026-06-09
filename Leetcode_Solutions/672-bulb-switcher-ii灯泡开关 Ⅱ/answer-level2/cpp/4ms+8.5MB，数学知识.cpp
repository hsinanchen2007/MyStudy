### 解题思路
在读题时可以发现，我们应该取一个模数，容易发现，当模数取6时，可以对题目中所有的情形进行概括，不妨设m=a1+a2+a3+a4,其中的ai表示执行第i个操作的次数，用同余的性质，可以将1...n的一系列编号根据其mod6的结果来分类，对于某一编号i，当i=6k+1时，执行n次操作后，若a1+a3+a4的值为偶数，则i灯亮；对于某一编号i，当i=6k+2时，执行n次操作后，若a1+a2的值为偶数，则i灯亮；对于某一编号3，当i=6k+3时，执行n次操作后，若a1+a3 的值为偶数，则i灯亮；对于某一编号i，当i=6k+4时，执行n次操作后，若a1+a2+a4的值为偶数，则i灯亮；对于某一编号i，当i=6k+5时，执行n次操作后，若a1+a3 的值为偶数，则i灯亮；对于某一编号i，当i=6k+6时，执行n次操作后，若a1+a2的值为偶数，则i灯亮；时间复杂度O(1);同时还要注意到，n>=6时，n的所有取值最后的结果会和n=6的结果一样，因为此时对n的mod6同余类都是一样的。

### 代码

```cpp
class Solution {
public:
    int flipLights(int n, int m) {
    bitset<4>*arr[16];
	int mod2[16];
	for (int j = 0; j < 16; j++)
	{
		arr[j] = new bitset<4>(j);
		mod2[j] = (arr[j]->count())%2;
	}
	if (n >= 6)
		n = 6;
	int m_mod_2 = m % 2;
	map < string, bool>mp;
	int kinds = 0;
	for (int i = 0; i < 16; i++)
	{
		if (mod2[i] != m_mod_2 ||arr[i]->count()>m)
			continue;
		string t = "";
		for (int j = 1; j <= n; j++)
		{
			switch (j)
			{
			case 1:
				t.push_back(((*arr[i])[0] + (*arr[i])[2] + (*arr[i])[3]) % 2 + '0');
				break;
			case 2:
				t.push_back(((*arr[i])[0] + (*arr[i])[1]) % 2 + '0');
				break;
			case 3:
				t.push_back(((*arr[i])[0] + (*arr[i])[2]) % 2 + '0');
				break;
			case 4:
				t.push_back(((*arr[i])[0] + (*arr[i])[1] + (*arr[i])[3]) % 2 + '0');
				break;
			case 5:
				t.push_back(((*arr[i])[0] + (*arr[i])[2]) % 2 + '0');
				break;
			case 6:
				t.push_back(((*arr[i])[0] + (*arr[i])[1]) % 2 + '0');
				break;
			}
		}
		if (mp.count(t) == 0)
		{
			mp[t] = true;
			kinds++;
		}
	}
	return kinds;
    }
};
```