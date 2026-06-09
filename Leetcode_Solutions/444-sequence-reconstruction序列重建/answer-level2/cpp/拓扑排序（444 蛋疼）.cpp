### 解题思路
唯一确定一个序列，注意这里是子序列。必须保证当前队首的元素在vec里面的排序，所以利用拓扑排序，保证一次只有一个入度为0的节点，而且该节点的值等于vec里面的值；

题解到了这里本该结束，但是出题人搞了很多蛋疼的用例，特别是针对org为1的情况，所以索性程序开始的时候先对1的情况特殊处理。

### 代码

```cpp
	class Solution {
	public:
		bool BfsIsLegal(map<int, vector<int>>& orgMap, vector<int>& inDgree, vector<int>& org)
		{
			queue<int> bfs;
			for (int i = 1; i < inDgree.size(); i++) {
				if (inDgree[i] == 0) {
					bfs.push(i);
				}
			}
			int index = 0;
			while(!bfs.empty()) {
				if (bfs.size() > 1) {
					return false;
				}
				int node = bfs.front();
				bfs.pop();
				if (node != org[index]) {
					return false;
				}
				for (auto item : orgMap[node]) {
					inDgree[item]--;
					if (inDgree[item] == 0) {
						bfs.push(item);
					}
				}
				index++;
			}
			return (index == org.size());
		}
		bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
			if (seqs.empty()) return false;
            if (org.size() == 1) {
                bool flag = false;
                for (auto seq : seqs) {
                    if (seq.empty()) {
                        continue;
                    }
                    if (seq.size() > 1) {
                        return false;
                    }
                    if (seq.size() == 1 && seq[0] == org[0]) {
                        flag = true;
                    }
                }
                return flag;
            }
			map<int, vector<int>> orgMap;
			vector<int> inDgree(org.size() + 1, 0);
			for (auto seq : seqs) {
				if (seq.size() <= 1) {
                    if (! seq.empty() && seq[0] > org.size()) {
                        return false;
                    }
					continue;
				}
				for (int i = 0; i < seq.size() - 1; i++) {
					if (seq[i] > org.size() || seq[i+1] > org.size()) {
						return false;
					}
					orgMap[seq[i]].push_back(seq[i+1]);
					inDgree[seq[i+1]]++;
				}
			}
            if (orgMap.empty()) {
                return false;
            }
			return BfsIsLegal(orgMap, inDgree, org);
		}
	};
```