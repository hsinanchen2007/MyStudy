这题直接贪心即可解，先记录下所有情侣和座位对应编号，然后开始迭代，找到与当前匹配的情侣进行交换，记录交换次数即可。

```cpp []
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        unordered_map<int, int> memo(row.size());
        
        for (int i = 0; i < row.size(); i++)
            memo[row[i]] = i;
        
        int next = 0; // 所期望的情侣
        for (int i = 0; i < row.size(); i += 2) {
            next = (row[i] & 1) ? row[i] - 1 : row[i] + 1;
            if (row[i + 1] == next) continue;
            
            swap(row[i + 1], row[memo[next]]);
            swap(memo[next], memo[row[memo[next]]]);
            res++;
        }
        
        return res;
    }
};
```

* 时间复杂度：O(N)
* 空间复杂度：O(N)