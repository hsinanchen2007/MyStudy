//回溯
//1.路径：记录到track中
//2.选择列表：start~n的部分
//3.结束条件：track_size == k

```

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        backtrack(n, 1, k, track);
        return result;
    }
    void backtrack(int n, int start, int k, vector<int>& track) {
        int track_size = track.size();
        if(track_size == k) {
            result.push_back(track);
            return;
        }
        for(int i = start; i <= n; ++ i) {
            track.push_back(i);
            backtrack(n, i + 1, k, track);
            track.pop_back();
        }
    }
};
```
