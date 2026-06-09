### 解题思路
1，记录每次设置值的时间与取值
2，获取快照的时候，只需要二分查找离快照时间最近的取值即可，

### 代码

```cpp
class SnapshotArray {
public:
    struct Num {
        int time;
        int val;
        Num(int t, int v) : time(t), val(v) {}
        bool operator < (const Num& other) {
            return time < other.time;
        }
    };
    int time;
    int size;
    int snap_size;
    // 存放每一个时间下的某个index的取值
    vector<vector<Num> > nums;
    // 存放快照时间
    vector<int> snaps;
    SnapshotArray(int length) {
        time = 0;
        size = length;
        snap_size = 0;
        nums.resize(size);
        for (int i = 0; i < size; ++i) {
            nums[i].push_back(Num(time, 0));
        }
    }
    
    void set(int index, int val) {
        nums[index].push_back(Num(++time, val));
    }
    
    int snap() {
        snaps.push_back(time);
        return snap_size++;
    }
    
    int get(int index, int snap_id) {
        Num n = Num(snaps[snap_id] + 1, 0);
        return (--lower_bound(nums[index].begin(), nums[index].end(), n))->val;
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

![image.png](https://pic.leetcode-cn.com/f32ce4188dd5dbf6f844c674931dd001f55624f6a3a963326985a8350628c8eb-image.png)
