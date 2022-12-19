建议降级成中等难度
模拟正常人类的行为就好了嗷

```
 class Solution {
 public:
	 int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
		 int res = 0;
		 stack<int> boxes;   //开箱队列
		 for (int i = 0; i < initialBoxes.size(); i++) {
			 boxes.push(initialBoxes[i]);
		 }
		 while (!boxes.empty()) {
			 int box = boxes.top();
			 boxes.pop();
			 if (status[box] == 1) {                           // 1是可以直接打开的箱子
				 for (int i = 0; i < keys[box].size(); i++) {
					 int boxK = keys[box][i];
					 if (status[boxK] == 0) {
						 status[boxK] = 1;            //拿到钥匙就去解锁
					 }
					 else if (status[boxK] == 2) {
						 status[boxK] = 1;
						 boxes.push(boxK);         // 2表示之前拿到过这个箱子，解锁后再次加入开箱队列
					 }
				 }
				 for (int j = 0; j < containedBoxes[box].size(); j++) {
					 boxes.push(containedBoxes[box][j]);
				 }
				 res += candies[box];
			 }
			 else
			 {
				 status[box] = 2;         //锁住的箱子标记为2，放一边
			 }
		 }
		 return res;
	 }
 };
```

