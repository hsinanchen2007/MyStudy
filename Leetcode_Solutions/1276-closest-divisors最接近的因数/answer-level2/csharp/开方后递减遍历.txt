# 解题思路
给定num先+2。进行开方，结果四舍五入，开始往下遍历，取模。
模等于0，符合num+2；模等于1，符合num+1。
# 代码
```
public class Solution {
    public int[] ClosestDivisors(int num) {
        num = num + 2;
		int sqrtRes = (int)Math.Round(Math.Sqrt(num), 0);
		int res = 1;
		for (; sqrtRes > 1; sqrtRes--)
		{
			if (num % sqrtRes <= 1)
			{
				res = num / sqrtRes;
				break;
			}
		}
		return new int[] { res,sqrtRes };
    }
}
```
