### 解题思路
使用并查集动态维护区间。
维护一个map，将值存入map，在map中寻找到该值的上界与下界，如果相邻，合并。

### 代码

```cpp
class SummaryRanges {
    struct Node{
        int lb;
        int rb;
        Node *fa = nullptr;
        Node(int _val): lb(_val), rb(_val){
        }
    };
    map<int, Node *> cont;

    inline Node *find(Node *u){
        if (u->fa == nullptr) return u;
        Node *v = u;
        for (;v->fa != nullptr;v = v->fa){ }
        u->fa = v;
        return v;
    }

    inline void unite(Node *u, Node *v){
        //x < y
        u = find(u);
        v = find(v);
        v->fa = u;
        u->rb = v->rb;
    }

public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    inline void addNum(int val) {
        Node* u = new Node(val);

        if (cont.find(val) != cont.end()) return;

        cont.insert(make_pair(val, u));
        auto iter = cont.lower_bound(val - 1);
        if (iter != cont.end() && (*iter).first == val - 1){
            unite((*iter).second, u);
        }
        iter = cont.upper_bound(val);
        if (iter != cont.end() && (*iter).first == val + 1){
            unite(u, (*iter).second);
        }
    }
    
    inline vector<vector<int>> getIntervals() {
        vector<vector<int> > ret;
        for (auto iter = cont.begin();iter != cont.end();iter = cont.upper_bound(((*iter).second)->rb)){
            vector<int> tmp = {((*iter).second)->lb, ((*iter).second)->rb};
            ret.push_back(tmp);
        }

        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```