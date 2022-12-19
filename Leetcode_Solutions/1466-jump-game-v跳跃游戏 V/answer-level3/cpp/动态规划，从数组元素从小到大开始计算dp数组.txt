很显然，arr数组**每个数的最大访问下标数中的最大值即是**我们要求的**结果**，记这些最大访问下标数为dp数组。
对于arr中下标为index的数，它的最大访问下标数dp[index]，是它左边d个数和右边d个数中可一步跳跃到的数的最大访问下标数中的最大值+1，因为从index起可以跳一步跳到那些数。
这样考虑就存在计算dp数组元素的先后问题，从左到右计算吗？观察示例1可以看到计算dp[2]时，我们只有dp[0]和dp[1]的值，但显然dp[2]还和dp[3]、dp[4]有关，但这时dp[3]、dp[4]的值还没求。因此从左到右计算不行，同理从右到左计算也不行。
那么应该按什么顺序计算？观察题目条件可以发现，人总是从高处跳往低处的，如果将低处的dp值都算完了，高处的自然能算了。因此我们**按arr值从小到大的顺序计算dp的值**。
首先我们要知道arr值从小到大排序后的原下标，这很讨厌，我只能在struct类型中加入了arr值和对应下标并重载了小于操作符来达到目的，代码中的vec[i].i就是排序后的原下标。
接下来，用max记录从index下标处能跳跃的最大跳数，注意此处记录的是最大跳数，比题目要求的最多访问数小了1。从index处向左根据题目限制检查能否跳到j位置（要注意的是**当index能跳到j时，必然已经能跳到j+1，j+2,……，index-1的任一位置了**，不考虑这一点的话就会重复检查跳跃的可能性，增加时间和空间复杂度，导致内存超限，我第一次提交就这样gg了）。若能从index跳到j，则将max和dp[j]+1比较大小，大的赋给max（dp[j]要是还没计算怎么办？说明arr[j]不比arr[index]小，index根本跳不到这个j处，所以不存在这种可能）。同理也要向右检查一遍。这时的max就是index处的最大跳数了。
最终结果返回max中最大的那个再加一。
PS：做这题时已经只剩25分钟左右了，想到动态规划很快，想到用struct来记录原下标又花了一些时间，想到内存超限那个方法时算是解题思路基本全出来了，这时还剩15分钟，代码水平太菜，根本来不及写。菜的抠脚啊，怎么办？
```
struct Node {
	int val, i;
	bool operator<(const Node& b)
	{
		if (this->val < b.val)
		{
			return true;
		}
		return false;
	}
};


class Solution {
public:
	int maxJumps(vector<int>& arr, int d) {
		vector<Node> vec;
		for (int i = 0; i < arr.size(); i++) {
			Node tmp;
			tmp.val = arr[i];
			tmp.i = i;
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end());
		vector<int> dp(arr.size(),0);
		for (int i = 0; i < vec.size(); i++) {
			int index = vec[i].i;   //排序后的原下标
			int max = 0;	//统计当前最大的跳跃数

			for (int j = index - 1; j >= index - d && j >= 0; j--) {	//从index-1开始向左检查能否跳到j
				if (arr[index] > arr[j]) {
					if (max < dp[j] + 1)
						max = dp[j] + 1;
				}
				else
					break;
			}
			for (int j = index + 1; j <= index + d && j < arr.size(); j++) {	//从index+1开始向右检查能否跳到j
				if (arr[index] > arr[j]) {
					if (max < dp[j] + 1)
						max = dp[j] + 1;
				}
				else
					break;
			}
			dp[index] = max;
		}
		int res = 0;	//记录最大的跳数
		for (int i = 0; i < arr.size(); i++) {
			if (res < dp[i])
				res = dp[i];
		}
		return res + 1;		//res记录了跳数，所以访问数要加1
	}
};
```
