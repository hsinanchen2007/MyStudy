思路是再建立一个动态数组这个动态数组中是记录每天股票的价格的下标我举个栗子
题中例子是{7,1,5,3,6,4}由小到大是1,3,4,5,6,7即下标为1是最小的，下标为3为第二，下标为5排第三以此类推可得一个动态数组{1,3,5,2,4,0},只要最后数字往前大于第一个数字就一定存在最大的利润
代码如下:
```
int maxProfit(vector<int>& prices) {
		//找出最大以及最小值
		int min = 0;
		int maxprofit = 0;
		min = prices[0];
		//int j = 0;
		//创立一个和价格一样长的动态数组
		vector<int>rank(prices.size(), 0);
		vector<int>prices1;
		prices1 = prices;
		int i = 0, j;
		//首先要不为空
		while (!prices1.empty()) {
			j = 0;
			//找出最小值
			for (i = 0; i < prices1.size(); i++) {
				if (min > prices1[i]) {
					min = prices1[i];
					j = i;
				}
			}
			//移除这个元素
			prices1.erase(prices1.begin() + j);
			//将下标移入这个排名数组最后呈现的就是数组数值有小到大的下标排名
			rank.push_back(j);
		}
		//再遍历排名数组
		int len = rank.size();
		//int signal = 0;
		while (len >= 0) {
			if (rank[0] >= rank[len-1]) {
				len--;
			}
			
			if (rank[0] < rank[len-1]) {
				break;
			}
		}

		if (len > 0) {
			return abs(prices[rank[len-1]]-prices[rank[0]]);
		}

		else {
			return 0;
		}
	}
编译器可以执行
![image.png](https://pic.leetcode-cn.com/82a9b9ef040d517924a41f7e47a8606f568b2b6679e3372f15ad6c3b4494a739-image.png)
结果如下:
![image.png](https://pic.leetcode-cn.com/610443d5e584017f53791721470efd0edb3acee8be7c8cd87c3560ecf011c760-image.png)
但LeetCode表示时间超时，让我非常郁闷
![1.png](https://pic.leetcode-cn.com/f349e5257e9f9e663360ab2e57b3b393d803d9344b6beb4cff5f5e8940f567a7-1.png)

