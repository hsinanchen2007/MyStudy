### 解题思路
这题说简单不简单说难不难，主要情况考虑周全了就不会出错，思路很好理解，我的思路大体上和官方给的差不多：
先设定一个结果集合，记为res
（1）插入区间之前的非区间直接加入res中
（2）插入区间重合的区间合并成一个区间
（3）插入区间之后的非重合区间直接加入res中
咋一看，思路so easy，（1）（3）没什么好说的，一个while循环控制边界就可以实现
(1)对应代码
`while (idx < n && newInterval[0]>intervals[idx][1]) {
			res.push_back(intervals[idx++]);	
		}`
(3)在2后面，已经保证了重合区间都在(2)中处理完成，所以只需要控制下标不越界
`while (idx < n)
			res.push_back(intervals[idx++]);`

那么重头戏来了，（2）怎么处理呢，在解释具体代码之前，先来看一下图示例子：
![算法图解.jpg](https://pic.leetcode-cn.com/c832d689b930f0894a15c5ed98d5c02513ab10e2c4611d68fb8e70a475f3d79f-%E7%AE%97%E6%B3%95%E5%9B%BE%E8%A7%A3.jpg)
那么对应部分代码就是：

    	 /*找重叠区间并合并*/
		if(idx < n){//左边界重叠部分的比较
			newInterval[0]=min( intervals[idx][0],newInterval[0]);
		}
		//找到与插入区间的右边界重叠部分
		while (idx < n && newInterval[1] >= intervals[idx][0]) 
			idx++;
		
		//idx等于n的情况：当新区间右边界大于原集合中的最大值
		if(idx <= n && idx>0){//右边界重叠部分比较
			newInterval[1] = max(intervals[idx - 1][1],newInterval[1]);
		}
		res.push_back(newInterval);//把合并的区间加入结果结合中


PS：自己开始敲代码也走了很多坑，分情况讨论的时候也写的很乱，一下忘了数组越界的情况，一下忘了原区间为空的情况...新手玩家总结不易，希望大家一起进步。


### 代码
```cpp
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		vector<vector<int>> res;
		int idx = 0, n = intervals.size();
		//把新区间前的区间直接复制到结果结合中
		while (idx < n && newInterval[0]>intervals[idx][1]) {
			res.push_back(intervals[idx++]);	
		}
		
		//找重叠区间并合并
		if(idx < n){
			newInterval[0]=min( intervals[idx][0],newInterval[0]);
		}
		
		//找到与插入区间的右边界重叠部分
		while (idx < n && newInterval[1] >= intervals[idx][0]) 
			idx++;
		//while循环退出时，若idx<n(还没有越界),那么此时idx指向的区间一定和插入区间没有交际，这也是为什么下一条if中是intervals[idx - 1]而不是intervals[idx]

		//idx等于n的情况：当新区间右边界大于原集合中的最大值
		if(idx <= n && idx>0){
			newInterval[1] = max(intervals[idx - 1][1],newInterval[1]);
		}

		res.push_back(newInterval);
		//如果插入区间与所有区间没有交际，上面if,while,if均不执行

		while (idx < n)//重合区间后的区间追加到结果区间即可
			res.push_back(intervals[idx++]);

		return res;
	}
};
```