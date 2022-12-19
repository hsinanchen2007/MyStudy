看这个题目想到可能可以用并查集，就看了下题解，递归和非递归的查找都实现了

* 并查集的大小：取最大的子进程id+1，可以减少计算
* 合并的方法和普通并查集一致
* 查找的方法，普通方法一直找，找到根节点（f[x]=x）为止；这里为了得到最终结果，如果向上查找到了kill节点，就不再继续查找；

```
class Solution {
public:
    
    vector<int> m;
    int gkill = 0;

    int find1(int x) {
        while (m[x] != x) {
            if (x == gkill) {
                m[x] = x;
                return x;
            } else {
                x = m[x];
            }
        }
        return x;
    }

    int find(int x) {
        if (m[x] != x) {
            if (x == gkill) {
                m[x] = x;
            } else {
                m[x] = find(m[x]);
            }
        }
        return m[x];
    }

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int msize = *max_element(pid.begin(), pid.end());
        for (int i = 0; i < msize + 1; ++i) {
            m.push_back(i);
        }
        gkill = kill;
        for (int i = 0; i < pid.size(); ++i) {
            int fx = find(pid[i]);
            int fy = find(ppid[i]);
            if (fx != fy) {
                m[fx] = fy;
            }
        }
        vector<int> ans;
        for (int i = 0; i < pid.size(); ++i) {
            if (find(pid[i]) == kill) {
                ans.push_back(pid[i]);
            }
        }
        return ans;
    }
};

```

击败 99.39%