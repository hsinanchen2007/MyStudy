### 解题思路
用一个堆维护所有当前空闲的区间，同时用两个哈希表记录每个位置左边和右边是否有区间（这样在有人离开座位，需要合并区间的时候就会更加方便。）

### 代码

```cpp
struct Segment {
    int l, r, no, dist;
    bool operator<(const Segment &that) const {
        return dist > that.dist || (dist == that.dist && no < that.no);
    } 
};

class ExamRoom {
    int N;
    unordered_map<int, vector<Segment>> left, right;
    set<Segment> s;
    void add_segment(int l, int r) {
        l = max(l, 1);
        r = min(r, N);
        if (r < l)
            return;
        int mid = (l + r) / 2;
        int dist = mid - l + 1;
        if (l == 1) {
            mid = 1;
            dist = r;
        } else if (r == N) {
            mid = r;
            dist = r - l + 1;
        }
        Segment new_segment {l, r, mid, dist};
        s.insert(new_segment);
        left[r + 1].emplace_back(new_segment);
        right[l - 1].emplace_back(new_segment);
    }
    
    void remove_segment(Segment &segment) {
        auto [l, r, no, dist] = segment;
        s.erase(segment);
        left[r + 1].clear();
        right[l - 1].clear();
    }
    
public:
    ExamRoom(int N) {
        this->N = N;
        Segment start{1, N, 1, N};
        s.insert(start);
        right[0].emplace_back(start);
        left[N + 1].emplace_back(start);
    }
    
    int seat() {
        Segment best = *s.begin();
        remove_segment(best);
        auto [l, r, no, dist] = best;
        add_segment(l, no - 1);
        add_segment(no + 1, r);
        return no - 1;
    }
    
    void leave(int p) {
        p++;
        int l = p, r = p;
        if (!left[p].empty()) {
            Segment ls = left[p][0];
            l = ls.l;
            remove_segment(ls);
        }
        if (!right[p].empty()) {
            Segment rs = right[p][0];
            r = rs.r;
            remove_segment(rs);
        }
        add_segment(l, r);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
```