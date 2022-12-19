```
class Solution {
public://模拟算法
    //执行用时 :8 ms, 在所有 C++ 提交中击败了100.00%的用户
    //内存消耗 :9.7 MB, 在所有 C++ 提交中击败了100.00%的用户
    int i,j,cur,dist,max_len;
    int up[1001],down[1001];
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(i=0;i<trips.size();i++) {
            up[trips[i][1]] += trips[i][0];
            down[trips[i][2]] += trips[i][0];
            if(trips[i][2]>max_len) max_len = trips[i][2];
        }
        while(dist<=max_len) {
            cur += up[dist]-down[dist];
            if(cur>capacity) return false;//如果某个位置的乘客人数超过上限直接返回false
            dist++;
        }
        return true;
    }
};
```
