目前的题解并查集都是拿链表写的，这里提供一种数组写法


class Solution {
public:
    int *parent;
    double *value;
    int size;
    unordered_map<string, int> m;
    int idx = 0;


    int getPar(int x) {
        if (parent[x] == x) { return x; }
        int fx = getPar(parent[x]);
        return fx;
    }

    bool merge(int x, int y, double ratio) {
        int fx = getPar(x);
        int fy = getPar(y);
        if (fx == fy) { return false; }

        double fact = value[y] * ratio / value[x];

        for (int i = 0; i < size * 2; ++i) {
            if (getPar(i) == fx) { value[i] *= fact; }
        }

        parent[fx] = fy;

        return true;
    }

    double query(int x, int y) {
        int fx = getPar(x);
        int fy = getPar(y);
        if (fx != fy) { return -1; }
        return value[x] / value[y];
    }

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        size = values.size();
        parent = new int[size * 2 + 1];
        value = new double[size * 2 + 1];
        for (int i = 0; i < size * 2; ++i) {
            parent[i] = i;
            value[i] = 1;
        }
        for (int i = 0; i < size; ++i) {
            string x = equations[i][0];
            string y = equations[i][1];
            if (m.find(x) == m.end()) {
                m[x] = idx++;
                value[m[x]] = values[i];
            }
            if (m.find(y) == m.end()) {
                m[y] = idx++;
                value[m[y]] = 1.0;
            }
            merge(m[x], m[y], values[i]);
        }
        vector<double> ans;
        for (vector<string> q: queries) {
            string x = q[0], y = q[1];
            if (m.find(x) == m.end() or m.find(y) == m.end()) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(query(m[x], m[y]));
        }
        return ans;
    }
};