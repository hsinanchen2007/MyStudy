### 解题思路

1. 默认值是0，用来兜底；
2. 因为1），所以如果找不到快照修改就返回上个兜底值。

### 代码

```cpp
class SnapshotArray {
private:
    vector<map<int, int>> sa;
    long snapId;
public:
    SnapshotArray(int length) {
        sa.resize(length);
        snapId = 0L;
        for(int i=0; i<length; i++)
            sa[i][snapId] = 0;
    }
    
    void set(int index, int val) {
        sa[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = sa[index].lower_bound(snap_id);
        if(it == sa[index].end() || it->first > snap_id)
            --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
```