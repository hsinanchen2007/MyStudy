### 解题思路

![image.png](https://pic.leetcode-cn.com/49c2c88ded6522bc7ba81a088b240c8dc8c2d0cfb4741f72a06580b0fa0ff769-image.png)
其实就是去搜
### 代码

```cpp
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<pair<string, string>, double> mm;
        map<pair<string, string>, double> mm2;
        set<string> ss;
        set<string> ss_find;
        map<string, pair<char, double>> keym;
        int len = equations.size();

        for (int i = 0; i < len; i++) {
            //缓存所有公式
            mm[make_pair(equations[i][0], equations[i][1])] = values[i];
            mm[make_pair(equations[i][1], equations[i][0])] = 1.0 / values[i];
            ss.insert(equations[i][0]);
            ss.insert(equations[i][1]);
        }
        bool first = true;
        //标记基准，即图之间是否联通
        char now_ele = 'a';
        while (!ss.empty()) {
            //存取某次搜索找到的元素集合
            set<string> t_s;
            for (auto it = ss.begin(); it != ss.end(); it++) {
                string now = *it;
                bool find_now = false;
                //某个图的第一个元素
                //根据之前的结果找到这个元素
                if (first) {
                    keym[now] = make_pair(now_ele, 1.0);
                    t_s.insert(now);
                    ss_find.insert(now);
                    first = false;
                    find_now = true;
                } else {
                    for (auto it2 = ss_find.begin(); it2 != ss_find.end(); it2++) {
                        string fri = *it2;
                        if (fri == now) continue;
                        pair key1 = make_pair(now, fri);
                        //pair key2 = make_pair(fri, now);
                        if (mm.find(key1) != mm.end()) {
                            char ele = keym[fri].first;
                            double r = keym[fri].second * mm[key1];
                            keym[now] = make_pair(ele, r);
                            t_s.insert(now);
                            ss_find.insert(now);
                            find_now = true;
                            break;
                        }
                    }
                }
                if (!find_now) continue;
                //遍历之前元素，找到与本元素关联的其他元素
                for (auto it3 = ss.begin(); it3 != ss.end(); it3++) {
                    string fri2 = *it3;
                    if (fri2 == now) continue;
                    if (ss_find.find(fri2) != ss_find.end()) continue;
                    pair key1 = make_pair(now, fri2);
                    if (mm.find(key1) != mm.end()) {
                        t_s.insert(fri2);
                        ss_find.insert(fri2);
                        char ele = keym[now].first;
                        double r = keym[now].second / mm[key1];
                        keym[fri2] = make_pair(ele, r);
                    }
                }
            }
            if (t_s.empty()) {
                first = true;
                now_ele++;
                continue;   
            }
            for (auto it = t_s.begin(); it != t_s.end(); it++) {
                ss.erase(*it);
            }
            t_s.clear();
        }

        vector<double> res;
        len = queries.size();
        //解答
        for (int i = 0; i < len; i++) {
            string key1 = queries[i][0];
            string key2 = queries[i][1];
            if (keym.find(key1) == keym.end() || keym.find(key2) == keym.end() || keym[key1].first!=keym[key2].first) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(keym[key1].second / keym[key2].second);
        }     
        return res;
    }
};
```