
暴力法是找出所有和的情况，然后遍历一遍，取%3==0的最大值
优化思路是：我们只需要动态更新遍历过的元素之和中 n%3==0，n%3==1，n%3==2的三个最大值即可舍弃其它和的情况

动态更新：复杂度o（n）
执行用时 :56 ms
内存消耗 :11.7 MB

```
class Solution {

public:
    int maxSumDivThree(vector<int>& nums) {
	vector<int> ans(3, 0);//ans[0],ans[1],ans[2]分别保存遍历过的元素的和中%3==0，%3==1，%3==2的最大值
	vector<int>temp(3, 0);

	for (auto num : nums) { //遍历nums
		for (auto a : ans) {  //将ans中每个元素与num求和
		    if ((num + a) % 3 == 0) temp[0] = max(num + a, temp[0]); //如果当前和 %3==0  且大于之前的temp[0]则更新temp[0]
		    else if ((num + a) % 3 == 1)temp[1] = max(num + a, temp[1]);//同上
		    else if ((num + a) % 3 == 2)temp[2] = max(num + a, temp[2]);//同上

		}
		ans = temp;//将修正过的temp赋给ans
	}
	return ans[0];//完成遍历返回a[0]即可
   }
};

```





