### 解题思路
Tom和Jerry的博弈，每一次选择，其实都是一棵树的分支而已，所以可以用DFS：首先分析一下平局的情况， *“如果某一位置重复出现（即，玩家们的位置和移动顺序都与上一个回合相同），游戏平局。”* 因此可以理解为Tom遍历一次地图，然后Jerry也遍历了一次地图，那么再一次进入，他的动作肯定就会重复，所以平局应该是在递归深度为2N的时候出现。

其次分析一下Tom获胜的场景：先根遍历，如果当前两个人在同一个位置，那么Tom获胜；  如果当前是Tom的局，递归调用DFS，只要返回2，那么说明Tom能走一步抓到Jerry，Jerry跑不掉；如果发现是平局，那么这也不失为一种方案，记录下来；但如果发现是Jerry胜利，那么就不走这个点，但如果遍历完Nextcode，没有找到胜利的走法，那么只能返回1，Jerry获胜。

Jerry的场景也一样。

当然这里需要记忆话搜索，不然会超时。

### 代码

```cpp
class Solution {
public:
	int DFSGetResults(vector<vector<int>>& mapNode, vector<vector<vector<int>>>& BPState, int currentTime, int jerryNode, int tomNode)
	{
		if (currentTime == mapNode.size() * 2) {
            BPState[currentTime][jerryNode][tomNode] = 0;
			return 0;
		}
		if (BPState[currentTime][jerryNode][tomNode] != -1) {
			return BPState[currentTime][jerryNode][tomNode];
		}
		if (jerryNode == 0) {
            BPState[currentTime][jerryNode][tomNode] = 1;
			return 1;
		}
		if (jerryNode == tomNode) {
            BPState[currentTime][jerryNode][tomNode] = 2;
			return 2;
		}
		bool isDraw = false;
		if (currentTime%2 == 0) {
			for (auto item : mapNode[jerryNode]) {
				switch (DFSGetResults(mapNode, BPState, currentTime + 1, item, tomNode))
                {
                    case 1:
                        BPState[currentTime][jerryNode][tomNode] = 1;
						return 1;
					case 0:
						isDraw = true;
						break;
					default:
						continue;
                }
			}
			if (! isDraw) {
                BPState[currentTime][jerryNode][tomNode] = 2;
				return 2;
			}
		} else {
			for (auto item : mapNode[tomNode]) {
                if (item != 0) {
                    switch (DFSGetResults(mapNode, BPState, currentTime + 1, jerryNode, item))
                    {
                        case 2:
                            BPState[currentTime][jerryNode][tomNode] = 2;
                            return 2;
                        case 0:
                            isDraw = true;
                            break;
                        default:
                            continue;
                    }	
			    }
            }
			if (! isDraw) {
                BPState[currentTime][jerryNode][tomNode] = 1;
				return 1;
			}
		}
        BPState[currentTime][jerryNode][tomNode] = 0;
        return 0;
	}
    int catMouseGame(vector<vector<int>>& graph) {
		vector<vector<int>> mapNode(graph.size(), vector<int>());
		for (int i = 0; i < graph.size(); i++) {
			for (auto item : graph[i]) {
				mapNode[i].push_back(item);
			}
		}
		vector<vector<vector<int>>> BPState(2*graph.size() + 1, vector<vector<int>>(graph.size(), vector<int>(graph.size(), -1)));
		return DFSGetResults(mapNode, BPState, 0, 1, 2);
    }
};
```