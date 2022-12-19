
### 带权值的并查集

#### unionSet 的 成员属性有

fa 记录的是每个节点的父节点是谁。
val 记录的是每个节点到其父节点的权值

#### 成员方法有
getFather 获取父节点，并在获取父节点的同时进行了路径压缩,以及权值的压缩。

这个相对好理解一些，路径压缩就是将当前节点挂到其父节点的父节点下，
那么当前节点到 其父节点的父节点 的 权值
就是 当前节点到其父节点的权值 * 当前节点的父节点 到 其父节点的父节点的权值。

merge 将两个节点a, b, 进行合并。
其实就是将b的父节点（bb）挂到a的父节点(aa)下面，这个时候val[bb]因为根节点发生了改变，所以其值也会发生改变。
那么,问题就变成了：

已知 

`a / b = c, aa / a = val[a], bb / b = val[b],`

求 

`aa / bb = ?` 

易得 

`aa / bb == ( a / b ) * ( aa / a ) / ( bb / b) ;`

所以 

`val[bb] = c * val[a] / val[b]; `

自此程序就可以写出来啦。

```c
class Solution {
private:
    class unionSet{
    private:
        unordered_map<string, string> fa;
        unordered_map<string, double> val;

        bool exist(const string& x) { return fa.find(x) != fa.end();}

        void init(const string& x) {
            if (exist(x)) return;
            val[x] = 1;
            fa[x] = x;
        }

        string getFather(const string& x) {
            if (fa[x] == x) return x;
            else {
                string f = getFather(fa[x]);
                val[x] = val[x] * val[fa[x]];
                return fa[x] = f;
            }
        }
    public:
        void merge(const string& a, const string& b, double v) {
            init(a);init(b);
            string aa = getFather(a), bb = getFather(b);
            fa[bb] = aa;
            val[bb] = val[a] * 1.0 / val[b] * v;
        }
        double ask(const string& a, const string& b) {
            if (!exist(a) || !exist(b)) return -1;
            string aa = getFather(a), bb = getFather(b);
            if (aa != bb) return -1;
            return val[b] * 1.0 / val[a]; 
        }
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unionSet u;
        for (int i = 0; i < equations.size(); i++) {
            u.merge(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(u.ask(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};
```
![2019-09-16 10-58-05 的屏幕截图.png](https://pic.leetcode-cn.com/9c99bfa08df40a5ae4615167a9dcda34e91131bbb254daa9706280e80ecffe82-2019-09-16%2010-58-05%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


