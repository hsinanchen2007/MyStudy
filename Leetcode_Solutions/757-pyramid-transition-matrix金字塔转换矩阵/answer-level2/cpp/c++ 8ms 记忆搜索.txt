

```
class Solution {
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {

		int layer = bottom.size();
		//mp是一个三维数组，它的结构就是一个金字塔，每个金字塔方块都存着可能出现的字符
		vector<vector<set<char>>> mp(layer);

		vector<bool> noempty(layer, false); //优化，如果这一层有字符才继续进行搜索
		for (int i = 0; i < layer; i++) {
			mp[i].resize(i + 1);
		}
		noempty[layer - 1] = true; //初始化，最底下一层是有字符的
		for (int i = 0; i < layer; i++) mp[layer - 1][i].insert(bottom[i]);

		for (int l = layer - 1; l >= 1; l--) {
			if (!noempty[l] || noempty[0]) break;
			for (int k = 0; k < l; k++) {
				for (int i = 0; i < allowed.size(); i++) {
					if (mp[l][k].count(allowed[i][0]) && mp[l][k + 1].count(allowed[i][1])) {   //如果allowed[i]可以堆下一层，将下一层的对应方块插入allowed[i][2]

						noempty[l - 1] = true, mp[l - 1][k].insert(allowed[i][2]);
					}
				}
			}
		}
		return noempty[0];
	}

};
```
