用500个可变数组 分别记录不同的分组情况就可以 当前分组满了就放到答案里即可.

以下是`Go` , `C++` 代码

```go
func groupThePeople(groupSizes []int) [][]int {
    ans := make([][]int, 0)

    cnt := make([][]int, 500)
    
    for i, v := range groupSizes {
        cnt[v] = append(cnt[v], i)
        if len(cnt[v]) == v {
            ans = append(ans, cnt[v])
            cnt[v] = make([]int, 0)
        }
    }
    fmt.Println(ans)
    return ans
}
```

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int > > ans;
        vector<int> cnt[505];
        for(int i=0, v; i< groupSizes.size(); i++){
            v = groupSizes[i];
            cnt[v].push_back(i);
            if (cnt[v].size() == v){
                ans.push_back(cnt[v]);
                cnt[v].clear();
            }
        }
        return ans;
    }
};
```