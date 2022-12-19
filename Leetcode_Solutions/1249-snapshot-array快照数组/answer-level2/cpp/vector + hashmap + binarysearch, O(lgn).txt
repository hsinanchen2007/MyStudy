1.  仔细分析一下，实际上不需要我们每次进行快照时复制数组中所有的值，进行保存一次，我们只需要要保存哪些值被修改过的快照即可。
2.  实际上我们可以用数组或者map来保存当前索引，每次快照的值，本题为了简单，我们用hashmap保存快照值。
3.  set操作时时，我们只需要将索引对应的快照赋给当前的val即可。
4.  snap操作时，我们只需要将snapid值加一
5.  get操作时，我们只需要找到该索引小于等于当前snapid时的最大值的snap时对应的值。
6.  如果不用map存储，实际用vector存储snap的值也可以，通过二分查找即可。
```
class SnapshotArray {
public:
    SnapshotArray(int length) {
        snapCnt = 0;
        map<int,int> t;
        t[0] = 0;
        
        for(int i = 0;i < length; ++i){
            arr.push_back(t);
        }
    }
    
    void set(int index, int val) {
        arr[index][snapCnt] = val;
    }
    
    int snap() {
        snapCnt++;
        return snapCnt-1;
    }
    
    int get(int index, int snap_id) {
       auto it = arr[index].upper_bound(snap_id);
       it--;
       return arr[index][it->first];
    }
private:
    vector<map<int,int>> arr;
    int snapCnt;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
```