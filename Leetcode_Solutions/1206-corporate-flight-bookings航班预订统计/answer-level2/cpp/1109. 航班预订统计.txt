
#### 方法1

差分法，使用数组维护前缀和，时间复杂度$O(N)$。

```c++ []
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> tmp(n+2, 0);
        for(auto& it : bookings){
            tmp[it[0]] += it[2];
            tmp[it[1]+1] -= it[2];
        }
        int sum = 0;
        for(int i = 1;i <= n;++i){
            tmp[i] += tmp[i-1];
        }
        return vector<int>(tmp.begin()+1,tmp.end()-1);
    }
};
```

#### 方法2

同样是差分，不过换成了树状数组来维护前缀和。

```c++ []
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        bits.resize(n+1, 0);
        for(auto& it : bookings){
            add(it[0],it[2]);
            add(it[1]+1,-it[2]);
        }
        vector<int> ans;
        for(int i = 1;i <= n;++i){
            ans.push_back(query(i));
        }
        return ans;
    }
private:
    vector<int> bits;
    int query(int x){
        int s = 0;
        while(x > 0){
            s += bits[x];
            x -= lowbit(x);
        }
        return s;
    }
    void add(int x, int v){
        while(x <= bits.size()-1){
            bits[x] += v;
            x += lowbit(x);
        }
    }
    inline int lowbit(int x){
        return x & (-x);
    }
};
```
