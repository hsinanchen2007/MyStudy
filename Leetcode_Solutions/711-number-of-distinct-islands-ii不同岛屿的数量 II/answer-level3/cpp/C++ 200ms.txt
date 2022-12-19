```cpp
class UnionFindWithCount {
public:
    int count;
    vector<int> nodes;

    UnionFindWithCount(int n) {
        count = n;
        nodes = vector<int>(n);
        for (int i = 0; i < n; ++i)
            nodes[i] = i;
    }

    int find(int i) {
        if (nodes[i] == i)
            return i;
        return nodes[i] = find(nodes[i]);
    }

    void unionAB(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            count--;
            nodes[a] = b;
        }
    }
};

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<unordered_set<int>*> uniMap;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1) {
                    unordered_set<int>* tmp = new unordered_set<int>();
		    dfsUni2(grid, i, j, *tmp);
		    uniMap.push_back(tmp);
		}
	auto f1 = [](int x, int y)->pair<int, int> {return{ x,y }; };
	auto f2 = [](int x, int y)->pair<int, int> {return{ -x,y }; };
	auto f3 = [](int x, int y)->pair<int, int> {return{ x,-y }; };
	auto f4 = [](int x, int y)->pair<int, int> {return{ -x,-y }; };
	auto f5 = [](int x, int y)->pair<int, int> {return{ y,x }; };
	auto f6 = [](int x, int y)->pair<int, int> {return{ -y,x }; };
	auto f7 = [](int x, int y)->pair<int, int> {return{ y,-x }; };
	auto f8 = [](int x, int y)->pair<int, int> {return{ -y,-x }; };
	vector<pair<int, int>(*)(int, int)> f{ f1, f2 ,f3,f4,f5,f6,f7,f8 };
	UnionFindWithCount uf(uniMap.size());
	for (int i = 0; i < uniMap.size(); ++i)
	    for (int j = i + 1; j < uniMap.size(); ++j)
		if (uniMap[i]->size() == uniMap[j]->size() && check711(*uniMap[i], *uniMap[j], f))
		    uf.unionAB(uf.find(i), uf.find(j));
	return uf.count;
    }

    bool check711(unordered_set<int>& a, unordered_set<int>& b, vector<pair<int, int>(*)(int, int)>& f) {
        int count = a.size();
        int countXA = 0;
        int countYA = 0;
        for (auto& t : a) {
            countXA += t / 100;
            countYA += t % 100;
        }
        unordered_set<int> tmp;
	for (auto& func : f) {
	    int countXB = 0;
	    int countYB = 0;
	    for (auto& t : b) {
		pair<int, int> p = func(t / 100, t % 100);
		tmp.insert(p.first * 100 + p.second);
		countXB += p.first;
		countYB += p.second;
	    }
	    if ((countXB - countXA) % count == 0 && (countYB - countYA) % count == 0 && compareSet(a, tmp, (countXB - countXA) / count, (countYB - countYA) / count))
                return true;
            tmp.clear();
	}
	return false;
    }

    bool compareSet(unordered_set<int>& a, unordered_set<int>& b, int diffX, int diffY) {
        for (unordered_set<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
            if (!b.count((*iter / 100 + diffX) * 100 + *iter % 100 + diffY))
                return false;
        return true;
    }

    void dfsUni2(vector<vector<int>>& grid, int x, int y, unordered_set<int>& result) {
        if (grid[x][y] == 2)
            return;
        grid[x][y] = 2;
        result.insert((x + 50) * 100 + (y + 50));
        if (x != 0 && grid[x - 1][y] == 1)
            dfsUni2(garid, x - 1, y, result);
        if (x != grid.size() - 1 && grid[x + 1][y] == 1)
            dfsUni2(grid, x + 1, y, result);
        if (y != 0 && grid[x][y - 1] == 1)
            dfsUni2(grid, x, y - 1, result);
        if (y != grid[0].size() - 1 && grid[x][y + 1] == 1)
            dfsUni2(grid, x, y + 1, result);
    }
};
```
