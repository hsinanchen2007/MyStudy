### 解题思路
1. 把每一个DNA序列看作是八棵四叉树组成，所以说具体到每个字符就是单独的一棵四叉树，只不过每个四叉树有多少个节点就要根据基因库来判断。

### 代码

```cpp
class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set dict(bank.begin(), bank.end());
		if (!dict.count(end)) return -1;
		deque<string> de{ start };
		int step = 0;
		while (!de.empty())
		{
			int n = de.size();
			// 遍历每一层的序列
			step++;
			for (int i = 0; i < n; i++)
			{
				auto dna = de.front(); de.pop_front();
				// 把每个序列的每个字符看作是一颗四叉树进行层次遍历
				for (int j = 0; j < dna.size(); j++)
				{
					string tmp_dna = dna;
					for (auto element : string("ATGC"))
					{
						tmp_dna[j] = element;
						if (tmp_dna == end) return step;
						// 判断是否存在这一树的节点
						if (dict.count(tmp_dna))
						{
							de.push_back(tmp_dna);
							dict.erase(tmp_dna);
						}
					}
				}
			}
		}
		return -1;
	}
};

```