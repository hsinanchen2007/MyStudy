[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

解法与接雨水这道题类似。

题目中的条件，一个孩子的评分。如果比相邻的孩子的评分高，应该得到更多的糖果。

相邻关系分为左边和右边。

先看左邻居。

如果比左邻居评分高，个数加1。如果比左邻居评分低，个数设为1。
```
//每个人的评分。
vector<int> left(N,0);
left[0]=1;
for(int i=1;i<N;i++){
	if(ratings[i] > ratings[i-1]){
		left[i] = left[i-1] + 1;
	}else if(ratings[i] <= ratings[i-1]){
		left[i] = 1;lin
	}
}
```
再看右邻居。

思路类似，如果比右邻居评分高，个数加1。如果比右邻居评分低，个数设为1。
```
vector<int> right(N,0);
right.back()=1;
for(int i=N-2;i>=0;i--){
	if(ratings[i] > ratings[i+1]){
		right[i] = right[i+1] + 1;
	}else if(ratings[i] <= ratings[i+1]){
		right[i] = 1;
	}
}
```
这样，每个人的个数应该是两种个数的最大值。因为这样才能满足，只要比相邻的孩子评分高，就应该获得更多的糖果。
```
int s= 0;
for(int i=0;i<N;++i){
	s += max(left[i],right[i]);
}
```
综合起来：
```
int candy(vector<int>& ratings) {
	const int N=ratings.size();
	if(N==0) return 0;
	if(N==1) return 1;
	vector<int> left(N,0);
	left[0]=1;
	for(int i=1;i<N;i++){
		if(ratings[i] > ratings[i-1]){
			left[i] = left[i-1] + 1;
		}else if(ratings[i] <= ratings[i-1]){
			left[i] = 1;
		}
	}
	vector<int> right(N,0);
	right.back()=1;
	for(int i=N-2;i>=0;i--){
		if(ratings[i] > ratings[i+1]){
			right[i] = right[i+1] + 1;
		}else if(ratings[i] <= ratings[i+1]){
			right[i] = 1;
		}
	}
	int s= 0;
	for(int i=0;i<N;++i){
		s += max(left[i],right[i]);
	}
	
	return s;
}
```
可以继续简化。

因为最终结果是求max，只需知道两个值。并不需要存储从右到左扫描的值。

可删除第二个数组。
```
int candy(vector<int>& ratings) {
	const int N=ratings.size();
	if(N==0) return 0;
	if(N==1) return 1;
	vector<int> left(N,0);
	left[0]=1;
	for(int i=1;i<N;i++){
		if(ratings[i] > ratings[i-1]){
			left[i] = left[i-1] + 1;
		}else if(ratings[i] <= ratings[i-1]){
			left[i] = 1;
		}
	}
	int right = 1;
	int s = 0;
	s += max(left[N-1],right);
	for(int i=N-2;i>=0;i--){
		if(ratings[i] > ratings[i+1]){
			right = right + 1;
		}else if(ratings[i] <= ratings[i+1]){
			right = 1;
		}
		s += max(left[i],right);
	}
	
	return s;
}
```