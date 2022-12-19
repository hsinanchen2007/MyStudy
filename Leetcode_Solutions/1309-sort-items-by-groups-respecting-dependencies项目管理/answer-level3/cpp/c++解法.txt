### 解题思路
#### 整体思路是
- 先构建以小组为结点的AOV网，进行组间拓扑排序，得到序列`groupOrder`；然后项目之间拓扑排序，得到序列`result`；最后进行基数排序
#### 一些处理：
- 分组方法
	- 对于有人接手的项目，组号就是那个小组的序号；
	- 对于无人接受的项目，一个项目就是一个小组，组号为`m++`
- 拓扑排序用到了一些辅助数据结构：
	- 邻接表`groupAdjacencyList`，保存结点的后继关系
	- 结点的入度表`groupInDegreeTable`
- 基数排序：
	- 将组间拓扑排序得到的组的顺序号看作是十位数
	- 将项目拓扑排序得到的项目的顺序号看作是个位数

### 代码

```cpp
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
		int projectNumbers = n;       // 项目的数量
		int groupNumbers = m;         // 小组的数量

		// 重新编排组号`group`，并且更新组数`groupNumbers`
		for (auto& groupID : group) {
			if (groupID == -1) {
				groupID = groupNumbers++;
			}
		}

		// 生成组间依赖：前置依赖和后置依赖
		auto groupAdjacencyList = vector<vector<int>>(groupNumbers);
		auto groupInDegreeTable = vector<int>(groupNumbers);
		GenGroupDependence(projectNumbers, groupNumbers, group, beforeItems, groupAdjacencyList, groupInDegreeTable);

		// 进行组间拓扑排序
		vector<int> groupOrder;
		GroupTopologicalSort(groupNumbers, groupAdjacencyList, groupInDegreeTable, groupOrder);
		if (groupOrder.size() != groupNumbers) {
			return {};
		}

		// 项目之间拓扑排序
		vector<int> result;
		ProjectTopologicalSort(projectNumbers, beforeItems, result);
		if (result.size() != projectNumbers) {
			return {};
		}

		// 基数排序
		ProjectRadixSort(groupNumbers, groupOrder, group, result);

		return result;
	}



	/**
	遍历项目的逆邻接表`beforeItems`：
		得到组的邻接表`groupAdjacencyList`
		和组的入度表`groupInDegreeTable`
	*/
	void GenGroupDependence(int projectNumbers, int groupNumbers, const vector<int>& group, const vector<vector<int>>& beforeItems,
		vector<vector<int>>& groupAdjacencyList, vector<int>& groupInDegreeTable) {

		// 生成组的邻接表
		for (int projectID = 0; projectID < projectNumbers; projectID++) {
			int groupID = group[projectID];			// 当前项目所在组的ID
			for (auto beforeProjectID : beforeItems[projectID]) {
				int beforeGroupID = group[beforeProjectID];		// 依赖项目所在组的ID
				if (groupID != beforeGroupID) {

					// `beforeGroupID->groupID`依赖关系是否已经存在了
					bool isExist = false;
					for (auto afterGroupIDExisted : groupAdjacencyList[beforeGroupID]) {
						if (afterGroupIDExisted == groupID) {
							isExist = true;
							break;
						}
					}
					// 如果组间依赖不存在，则添加到邻接表里面去
					if (!isExist) {
						groupAdjacencyList[beforeGroupID].push_back(groupID);
					}
				}
			}
		}

		// 生成组的入度表
		for (int groupID = 0; groupID < groupNumbers; groupID++) {
			for (auto afterGroupID : groupAdjacencyList[groupID]) {
				groupInDegreeTable[afterGroupID]++;
			}
		}

	}

	/**
	组间进行拓扑排序
	*/
	void GroupTopologicalSort(int groupNumbers, const vector<vector<int>>& groupAdjacencyList, vector<int>& groupInDegreeTable,
		vector<int>& groupOrder) {

		// 初始化栈，存放入度为0的小组
		stack<int> zeroInDegreeGroups;
		for (int groupID = 0; groupID < groupNumbers; groupID++) {
			if (groupInDegreeTable[groupID] == 0) {
				zeroInDegreeGroups.push(groupID);
			}
		}

		// 持续地从栈中取出入度为0的小组，并且加入入度为0的小组
		int order = 0;		// 拓扑排序的序号
		while (!zeroInDegreeGroups.empty()) {
			// 取出入度为0的小组
			int groupID = zeroInDegreeGroups.top();
			zeroInDegreeGroups.pop();
			groupOrder.push_back(groupID);
			// 从图中“删除这些结点”，并且将后继结点的入度减一
			for (auto afterGroupID : groupAdjacencyList[groupID]) {
				if (--groupInDegreeTable[afterGroupID] == 0) {
					zeroInDegreeGroups.push(afterGroupID);
				}
			}
		}
	}

	/**
	项目间进行拓扑排序
	*/
	void ProjectTopologicalSort(int projectNumbers, const vector<vector<int>>& beforeItems,
		vector<int>& result) {
		// 构建项目的邻接表
		auto projectAdjacencyList = vector<vector<int>>(projectNumbers);
		for (int projectID = 0; projectID < projectNumbers; projectID++) {
			for (auto beforeProjectID : beforeItems[projectID]) {
				projectAdjacencyList[beforeProjectID].push_back(projectID);
			}
		}

		// 构建项目的入度表，并初始化辅助栈
		auto projectInDegreeTable = vector<int>(projectNumbers);
		stack<int> projectZeroInDegree;
		for (int projectID = 0; projectID < projectNumbers; projectID++) {
			projectInDegreeTable[projectID] = beforeItems[projectID].size();
			if (projectInDegreeTable[projectID] == 0) {
				projectZeroInDegree.push(projectID);
			}
		}

		// 拓扑排序
		while (!projectZeroInDegree.empty()) {
			int projectID = projectZeroInDegree.top();
			projectZeroInDegree.pop();
			result.push_back(projectID);

			for (auto afterProjectID : projectAdjacencyList[projectID]) {
				if (--projectInDegreeTable[afterProjectID] == 0) {
					projectZeroInDegree.push(afterProjectID);
				}
			}
		}
	}

	/**
	项目基数排序
	*/
	void ProjectRadixSort(int groupNumbers, const vector<int>& groupOrder, vector<int>& group, vector<int>& result) {
		auto collector = vector<vector<int>>(groupNumbers);
		// 进行一趟分配
		for (auto projectID : result) {
			collector[group[projectID]].push_back(projectID);
		}
		result.clear();
		// 进行一趟收集
		for (auto groupID : groupOrder) {
			for (auto projectID : collector[groupID]) {
				result.push_back(projectID);
			}
		}
	}
};
```