### 解题思路

这个题目并非难，难在有11亿个排座位，
这样的话就很麻烦，你不能建立 模型 去处理，会导致 用时 与 内存 不过关。

我的算法核心思想是： 1100排座位 最多能1100**22 == 2200 个家庭坐。
然后处理预定座位，确定一排有效家庭座位
![33.png](https://pic.leetcode-cn.com/f5bdb4bc9d0f0c6ddead358e0c3966ee0228db9b14694104732384b7af6d6bba-33.png)

由于reservedSeats 值是没有排序的， 使用map关联容器 防止 重复 减少 max;

还有优化的地方就是在 reservedSeats未排序值如何更好的关联所有排的座位

### 代码

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int max = 2 * n;
		map<int, vector<int>> val;

		for (auto& v : reservedSeats)
		{
			val[v[0]].push_back(v[1]);
		}

		bool x = 1, y = 1, z = 1;
		for (auto& v : val)
		{
            x = y = z = 1;
			for (auto& c : v.second)
			{
				switch (c)
				{
					case 1:
						break;
					case 2:
					case 3:
					{
						x = 0;
						break;
					}
					case 4:
					case 5:
					{
						x = 0;
						z = 0;
						break;
					}
					case 6:
					case 7:
					{
						y = 0;
						z = 0;
                        break;
					}
					case 8:
					case 9:
					{
						y = 0;
						break;
					}
					default:
						break;
				}
			}
            if (x && y && z)
                ;
			else if (!x && !y && !z)
				max -= 2;
			else if (x || y || z)
				max -= 1;
			else
				;
		}
		return max;
    }
};
```