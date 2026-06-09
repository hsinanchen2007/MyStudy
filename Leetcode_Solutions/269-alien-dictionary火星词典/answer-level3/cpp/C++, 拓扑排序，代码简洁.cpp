```
class Solution {
	typedef char key;
	typedef unordered_set<key> value;
	typedef unordered_map<key, value> umap;
	umap in_nodes;    // 入边统计
	umap out_nodes;   // 出边统计
public:
	string alienOrder(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i) {
			bool flag = false;
			for (int j = 0; j < words[i].size(); ++j) {
				if (!in_nodes.count(words[i][j]))
					in_nodes[words[i][j]] = value();
				if (!out_nodes.count(words[i][j]))
					out_nodes[words[i][j]] = value();
				if (i > 0 && j < words[i - 1].size() && !flag) {
					key from = words[i - 1][j];
					key to   = words[i][j];
					if (from != to) {
						if (!in_nodes[to].count(from))
							in_nodes[to].insert(from);
						if (!out_nodes[from].count(to))
							out_nodes[from].insert(to);
						flag = true;
					}
				}
			}
		}

		string result;
		vector<key> head;    // 拓扑入口点
		for (umap::iterator it = in_nodes.begin(); it != in_nodes.end(); ++it) {
			if (it->second.size() == 0)
				head.push_back(it->first);
		}
		for (int i = 0; i < head.size(); ++i) {
			result += head[i];
			queue<key> q;
			q.push(head[i]);
			while (!q.empty()) {
				key node = q.front();
				q.pop();
				for (value::iterator iit = out_nodes[node].begin(); iit != out_nodes[node].end(); ++iit) {
					if (in_nodes[*iit].count(node))
						in_nodes[*iit].erase(node);
					if (in_nodes[*iit].size() == 0) {
						result += *iit;
						q.push(*iit);
					}
				}
			}
		}
		return (result.size() == in_nodes.size()) ? result : "";
	}
};
```
