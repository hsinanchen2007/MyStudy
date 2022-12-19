### 解题思路
线段树 区间最值更新 + 离散化

### 代码

```cpp
// 线段树 区间最值
// 离散化

class Solution {  
private:
    struct Line {
        int x, left, right, c; 
        bool operator<(const Line& other)const {
            // 注意[[0,2,3],[2,5,3]] 这个case，这里一定要二次排序。。。坑
            if(this->x == other.x) {
                return this->c > other.c;
            }
            return this->x < other.x;
        }
        Line(int _x,int _left,int _right,int _c):x(_x),left(_left),right(_right),c(_c) {}
    };
    struct Node {
        int left, right, cover, len;
        Node():left(0),right(0),cover(0),len(0) {};
        Node(int l, int r, int c, int le):left(l),right(r),cover(c),len(le) {};
    };

    vector<Node> tree;
    vector<Line> lines;
    // 离散数组
    vector<int> p;
    // 离散数组的长度
    int n;
    void build_tree(int L, int R, int root = 1) {
        tree[root].left = p[L];
        tree[root].right = p[R];
        if(R - L <= 1) return;
        int M = (L + R) >> 1;
        build_tree(L, M, root << 1);
        build_tree(M, R, root <<1 | 1);
    }

    void push_up(int root) {
        if(tree[root].cover) {
            tree[root].len = tree[root].right - tree[root].left;
        } else {
            tree[root].len = tree[root<<1].len + tree[root<<1|1].len;
        }
    }

    void update(int L, int R, int c, int root = 1) {
        if(L <= tree[root].left && R >= tree[root].right) {
            tree[root].cover += c;
        } else {
            if(L < tree[root << 1].right) {
                update(L, R, c, root << 1);
            }
            if(R > tree[root<<1|1].left) {
                update(L, R, c, root << 1 | 1);
            }
        }
        push_up(root);
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()) return {};
        p.push_back(0);
        n = 1;
        for(int i =0; i < buildings.size(); i++){
            p.push_back(buildings[i][2]);
            // 把0 ~ building[i][2] 区间cover加1
            lines.push_back(Line(buildings[i][0], 0, p[n], 1));
            // 把0 ~ building[i][2] 区间的cover减1
            lines.push_back(Line(buildings[i][1], 0, p[n], -1));
            //ps: building[i][0]和building[i][1]可以理解为操作序号，我们需要按照序号从小到大执行这些操作。
            n++;
        }
        // 把离散区间排序
        sort(p.begin(), p.end());
        sort(lines.begin(), lines.end());
        tree.resize(n << 2 + 1);
        build_tree(0, n - 1);
        vector<vector<int>> ret; 
        for(auto line: lines) {
            auto pre_height = tree[1].len;
            update(line.left, line.right, line.c);
            auto cur_height = tree[1].len;
            if(cur_height != pre_height) {
                if(ret.empty()) {
                    ret.push_back({line.x, cur_height});
                    // 去重
                }else if(line.x != ret.back()[0]) {
                    ret.push_back({line.x, cur_height});
                } else {
                    ret.back()[1] = cur_height ;
                }
            }
        }
        return ret;
    }
};
```