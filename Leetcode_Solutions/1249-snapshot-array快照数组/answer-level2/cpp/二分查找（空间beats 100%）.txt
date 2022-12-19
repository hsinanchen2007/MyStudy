```
class SnapshotArray {
public:
//执行用时 :460 ms, 在所有 C++ 提交中击败了71.43%的用户
//内存消耗 :104.9 MB, 在所有 C++ 提交中击败了100.00%的用户
//本题不需要真的使用数组，只需要记录每个index在哪个snap发生了变化，使用了map
    int rec;
    map<int,int>::iterator it;
    unordered_map<int,map<int,int>> mp;
    SnapshotArray(int length) {
        rec = 0;
        mp.clear();
        for(int i=0;i<length;i++) mp[i][-1] = 0;//注意刚开始没有元素初始为0
    }
    
    void set(int index, int val) {
        mp[index][rec] = val;
    }
    
    int snap() {
        return rec++;
    }
    
    int get(int index, int snap_id) {
        it = mp[index].lower_bound(snap_id);
        if(it==mp[index].end()||it->first>snap_id) it--;
        return it->second;
    }
};
```
