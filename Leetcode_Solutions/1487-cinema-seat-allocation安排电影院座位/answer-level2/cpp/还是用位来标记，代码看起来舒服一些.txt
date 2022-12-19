思路就是用位来标记已订座，然后通过逻辑与操作来查看是不是有四连座。
但要注意的是，查找的时候需要根据`reservedSeats`数组来查找，然后拿`2*n`来减去不满足的四连座（每一行最大的四连座个数为2个），不然就会超时，不要问我怎么知道的（泪目，比赛没仔细看数据量大小）。
```
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> cache;
        for (auto & v : reservedSeats) cache[v[0]] |= (1 << v[1]);
        int cnt = 2*n;  
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            if ((it->second & 0x3fc) == 0) continue ; //先看是否能坐满2个四连座
            else if ((it->second & 0x3c0) == 0 || (it->second & 0x3c) == 0 || (it->second & 0xf0) == 0) 
                --cnt;
            else 
                cnt -= 2;
        }
        return cnt;
    }
};
```
