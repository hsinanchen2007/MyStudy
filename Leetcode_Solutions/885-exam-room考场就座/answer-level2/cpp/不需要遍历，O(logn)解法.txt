将连续空位的左右坐标编码作为value， 以空位中的最大距离和可坐的位置编码作为key。利用map的红黑树实现自动排序，取最大，删除和插入都是O(logn)。
```c++
typedef unsigned long LONG;
class ExamRoom {
public:
    ExamRoom(int N) {
        n = N;
        int tmp = 0;
        seats[encode(0, n+1, tmp)] = hash(0, n+1);
    }
    
    int seat() {
        auto it = seats.rbegin();
        int l = it->second >> 32;
        int r = it->second & 0xffffffff;
        //int tmp = 0;
        seats.erase(it->first);
        int pos = 0;
        if (l == 0) { //最左边还没人坐
            pos = 1;
        } else if (r == n+1) { //最右边没人坐
            pos = n;
        } else encode(l, r, pos); //当前最大空位的空间左边是l，右边是r。l和r都有人坐了
        
        left[l] = pos;
        right[pos] = l;
        left[pos] = r;
        right[r] = pos;
        int tmp = 0;
        if (pos - l > 1) seats[encode(l, pos, tmp)] = hash(l, pos);
        if (r - pos > 1) seats[encode(pos, r, tmp)] = hash(pos, r);
        return pos - 1;
    }
    
    void leave(int p) {
        p++;
        int l = right[p];
        int r = left[p];

        int tmp = 0;
        long s1 = encode(l, p, tmp);
        long s2 = encode(p, r, tmp);
        seats.erase(s1);
        seats.erase(s2);
       
        seats[encode(l, r, tmp)] = hash(l, r);
        left[l] = r;
        right[r] = l;
    }
    long hash(int l, int r) {
        long res = ((static_cast<long>(l)) << 32) + r;
        return res;
    }
    long encode(int l, int r, int& pos) { //pos返回l到r内可坐的那个位置，l和r都已经有人坐了。
        int dis = 0;
        if (l == 0) {
            dis = r - 2;
            pos = 1;
        } else if (r == n+1) {
            dis = n - l - 1;
            pos = n;
        } else {
            dis = (r - l - 2) / 2;
            pos = l + dis + 1;
        }
        LONG res = ((static_cast<LONG>(dis)) << 32) + (0xffffffff - pos);
        // cout << len << "," << l << "," << res << endl;
        return res;
    }
    map<LONG, LONG> seats;
    unordered_map<int, int> left; //以p为左端的连续空位的右端坐标
    unordered_map<int, int> right;//以p为 右端的连续空位的左端坐标
    int n;
};
```