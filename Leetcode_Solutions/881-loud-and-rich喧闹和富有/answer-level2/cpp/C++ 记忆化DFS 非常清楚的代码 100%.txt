```cpp
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
	vector<vector<int>> graph(quiet.size());
	for (vector<int>& vec : richer)
	    graph[vec[1]].push_back(vec[0]);
	vector<int> result(quiet.size());
	for (int i = 0; i < result.size(); ++i)
	    result[i] = i;
	for (int i = 0; i < quiet.size(); ++i)
	    dfsFindRich(graph, quiet, result, i, i);
	return result;
    }

    void dfsFindRich(vector<vector<int>>& graph, vector<int>& quiet, vector<int>& result, int t, int cur) {
	if (quiet[result[t]] > quiet[cur])
	    result[t] = cur;
	for (int& i : graph[cur]) {
	    if (i < t) {
		if (quiet[result[t]] > quiet[result[i]])
		    result[t] = result[i];
	    }
	    else
		dfsFindRich(graph, quiet, result, t, i);
	}
    }
};
```