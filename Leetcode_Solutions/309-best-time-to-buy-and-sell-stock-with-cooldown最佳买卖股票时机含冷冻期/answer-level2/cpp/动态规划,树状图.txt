### 解题思路

![截图找思路.png](https://pic.leetcode-cn.com/db5f6bd453415d4b949259e412391ec5679551fd673185a9ef2b54868d9e86a9-%E6%88%AA%E5%9B%BE%E6%89%BE%E6%80%9D%E8%B7%AF.png)

画树状图 节点是pair类型
first:  收益
second: 状态(0没有股票，1有股票，2冷冻)
下一天：
0: 买股票变为1, 或者保持0状态;
1: 卖股票变为2, 或者保持1状态;
2: 一定会‘解冻’变成0;
收益：根据状态转变对应改变。
![未命名文件(2).png](https://pic.leetcode-cn.com/5025d2d717362a79fffb93cdf50e55aa05fc041e7b080c78de939223143de822-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6\(2\).png)

第二天1状态下的（-1，1）和（-2，1），下一天他们只能卖或保持操作，不管什么操作，（-1，-1）的收益都会大于（-2，1），所以第三天及以后，可以不用考虑（-2，1）的分支节点情况了，同理0状态。因为冷冻2下一天的操作只能是解冻变为0，不能直接在今天就把它当作0，所以我们需要三个int变量分别保存0，1，2（冷冻）状态下最大的利益。


### 代码

```cpp
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
        if (n == 0) return 0;
		int have = 0,  			//状态1
            none = 0,  			//状态0
	        ice = -10000;   	//状态2
		have = -prices[0];
		int tmp1, tmp2;
		for (int i = 1; i < n; i++) {
			tmp1 = have+prices[i];      //新的2状态
			tmp2 = none - prices[i];	//新的1状态
			have = have > tmp2 ? have : tmp2;  //1状态下，最大的利益
			none = none > ice ? none : ice;    //0状态下，最大的利益
			ice = tmp1;
		}
		return max(ice, max(have, none));
	}
};
```