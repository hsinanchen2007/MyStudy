由题意可发现，当连续数列之和为目标值时，数列的中间值必为目标的因子。
奇数情况下,target%mid==0&&target/mid==奇数；
偶数情况下更简单，target%(mid+mid+1)==0；
找到数列中间值后，边界值可用target%mid来找到，奇偶实现略有不同，注意边界值需要从1开始。
```
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> res;
		int num = (target + 1) / 2;
		for (int i = 1; i < num; i++){
			if (i > 1 && target % i == 0) {//奇数情况
				vector<int> tmp;
				int n = target / i;
				int t = i - (n - 1) / 2;
				if (n % 2 == 1 && t > 0) {//注意n必须是奇数
					for (int j = t; j < t + n; j++)
						tmp.push_back(j);
					res.push_back(tmp);
				}
			}
			if (target % (i + i + 1) == 0) {//偶数情况
				vector<int> tmp;
				int n = target / (i + i + 1);
				int t = i + 1 - n;
				if (t > 0) {//注意边界
					for (int j = t; j < t + n * 2; j++)
						tmp.push_back(j);
					res.push_back(tmp);
				}
			}
		}
		return res;
	}
};
```
提交结果如下
![微信截图_20200306150335.png](https://pic.leetcode-cn.com/35cf1a43074deab689584be5548ae9a8131f77507550190100e166a641e92cb5-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200306150335.png)

