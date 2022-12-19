### 解题思路
执行结果：通过
执行用时 :12 ms, 在所有 cpp 提交中击败了98.32%的用户
内存消耗 :9.7 MB, 在所有 cpp 提交中击败了83.10%的用户
代码中写注释，方便捋思路，就是有点儿乱。
### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        size_t counts = deck.size();
		if (counts < 2 || counts > 10000)
			return false;

		std::map<int, int> p;
		for (auto de : deck)
		{
			++p[de];
		}
        /* 只有计数是必需品，所以键值对结构只用了second。 */
		std::vector<int> count;
		for (auto co : p)
		{
			if (co.second < 2)
				return false;     //  判定若要分组，组内至少有两个相同的数，所以计数至少为2，最大(counts - 2)。
			 //  排序（lower_bound()）并插入数据(（C++11）emplace(),insert()的内部实现)，并从小到大排序（默认的）。
			auto ite = std::lower_bound(count.begin(), count.end(), co.second);
			if (ite == count.end())    //  初始化：count对象需要初始赋值。
			{
				count.emplace(ite, co.second);
			}
			else
			{
				if (*ite != co.second)   // 排除重复的计数值。
				{
					count.emplace(ite, co.second);
				}
			}
		} 

		/*   下面求最小计数值的除最大和最小的约数都是什么。 X为选定的数字，X >= 2  */
		const int Min_COUNTS = count[0];
		for (int X = 2; X <= Min_COUNTS; X++)
		{
			if (counts % X == 0 && Min_COUNTS % X == 0)  //  首先分组表示deck的个数可以被X整除，并且还要是最小计数的约数。
			{
				auto ite = count.begin();
				for (; ite != count.end(); ite++)  //  使用迭代器是不得已而为之。
				{
					if (*ite % X != 0)   //  因为从最小的公约数开始的，这已经是最坏的情况。
						break;
				}
				if (ite == count.end())
					return true;         //  循环结束表示找到了合适的最小公约数。最坏情况是最小的计数值。
			}
			/*  如果不是公约数，由X++表示继续循环。用最小计数值把不符合要求的X去除。  */
		}
		return false;  //  循环结束表示没有找到适合的公约数。返回false。
	}
};
```

希望下次看能有更好的思路，而不是看不懂。
我连个简单都做不好，任重而道远。希望我不要放弃！！！