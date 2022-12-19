### 解题思路
关键思想类似n皇后**空位置nextBox**、**picBox**
此题目思路分为4个步骤

1.若当前盒子中包含有盒子则nextBox+1，存钥匙keysTaken，则向下递归
2.若当前盒子内不包含盒子，并且打开状态为1回溯
3.存储已经访问过的盒子，并且nextbox-1
4.跳出回溯递归后，把钥匙keysTaken与beforeBox进行比较，若相等，则代表
之前访问过的盒子也能打开，并把糖果数量累计相加。

### 代码

```cpp
class Solution {
public:
	void dfs(int index, std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys, std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes) {
		//回溯条件，若不是第一次，盒子里没有盒子，并且打开状态为0时返回
        if (index != initialBoxes[0]) {
			if (status[index]==0&&containedBoxes[index].size()==0) {
			return;
			}
		}
		//判断当前盒子是否开若开的能拿糖果
		if (status[index] == 1)candiesCount += candies[index];
	

		//有哪些盒子可以选
		std::vector<int> nextIndex ;
		//第一次递归时，将initalbox添加进去
		if (index == initialBoxes[0]) {
			for (int i = 1; i < initialBoxes.size(); i++) {
			nextIndex.push_back(initialBoxes[i]);
			}
		}
		for (int i = 0; i < containedBoxes[index].size(); i++) {
			nextIndex.push_back(containedBoxes[index][i]);
		}
		
		while(nextIndex.size()>0){
			//选一个盒子
			int picIndex = nextIndex.back();
			//拿钥匙
			for (int i = 0; i < keys[picIndex].size(); i++)
				keysTaken.push_back(keys[picIndex][i]);
			dfs(picIndex, status, candies, keys, containedBoxes, initialBoxes);
			//回溯
			//放以前未打开的箱子
			if(status[nextIndex.back()]==0)beforeBox.push_back(nextIndex.back());
			nextIndex.pop_back();
		}
	
	
	}
	int maxCandies(std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys, std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes) {
		if (initialBoxes.size() > 0) {
            	if(status[initialBoxes[0]]==0)
			beforeBox.push_back(initialBoxes[0]);
				for (int j = 0; j < keys[initialBoxes[0]].size(); j++)
					keysTaken.push_back(keys[initialBoxes[0]][j]);
				dfs(initialBoxes[0], status, candies, keys, containedBoxes, initialBoxes);
		}
		//把钥匙去重
		std::set<int>s(keysTaken.begin(), keysTaken.end());
		keysTaken.clear();
		keysTaken.assign(s.begin(), s.end());

		std::set<int>t(beforeBox.begin(), beforeBox.end());
		beforeBox.clear();
		beforeBox.assign(t.begin(), t.end());
		//拿之前的箱子并且未打开的与最后的钥匙匹配
		for (int i = 0; i < beforeBox.size(); i++) {
			for (int j = 0; j < keysTaken.size(); j++) {
				if (beforeBox[i] == keysTaken[j])
					candiesCount += candies[beforeBox[i]];
			}
		}
		return candiesCount;
	}
private:
	std::vector<int> beforeBox;//放以前拿的箱子,未打开的
	std::vector<int> keysTaken;
	int candiesCount = 0;//存放已经拿了多少糖果
};
```