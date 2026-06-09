### 解题思路
此处撰写解题思路
1、每次从x的一半res
2、res平方不大于x的，标记cnt。
3、如果res平方大于x的，则判断如果cnt有效则说明找到的res太大，res--；如果cnt无效，则继续第1点。

优化，res--，也可以用二分法找。
### 代码

```cpp
class Solution {
public:
	int mySqrt(int x) {
		if (x == 1)
			return 1;
		int res = x / 2;
		int cnt = 0;
		while (res > 0)
		{
            unsigned long long tmp = res * res;
			if (res > x/res)
			{
				if (cnt > 0) {	--res;	break;}
				else 
                {
                    res = res / 2;
                }
			}
			else{ cnt++;++res;}
		}
		return res;
	}
};

```