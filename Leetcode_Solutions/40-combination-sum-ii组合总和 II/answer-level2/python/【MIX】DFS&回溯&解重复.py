### 解题思路
DFS, 对重复解进行去除

### 代码

```java []
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        int N = candidates.length;
        if(N == 0)
            return res;

        // 升序排列
        Arrays.sort(candidates);
        ArrayList<Integer> comb = new ArrayList<>();
        makeCombination(candidates, 0, target, comb);
        return res;
    }

    private void makeCombination(int [] candidates, int index, int R, ArrayList<Integer> comb){
        if(R == 0){
            this.res.add(new ArrayList<>(comb));
            return;
        }

        int E = Integer.MAX_VALUE;
        for(int i=index; i<candidates.length; ++i){
            if(R < 0)
               break;
               
            if(candidates[i] != E){
                E = candidates[i];
                comb.add(E);
                makeCombination(candidates, i+1, R-candidates[i], comb);
                comb.remove(comb.size()-1);
            }
        }
    }

    private List<List<Integer>> res = new ArrayList<>();
}
```
```python3 []
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        N = candidates.__len__()
        self.res = []
        if N == 0:
            return self.res
        # self.used = [False for _ in range(N)]
        # 排序
        candidates.sort(key=lambda x: x)
        comb = []
        # 考虑解重复
        self.makCombination(candidates, 0, target, comb)
        return self.res

    def makCombination(self, candidates, index, R, comb):
        if R == 0:
            self.res.append(list(comb))
            return
        E = float('-inf')
        for i in range(index, len(candidates)):
            if R < 0:
                break
            if E != candidates[i]:
                E = candidates[i]
                comb.append(candidates[i])
                self.makCombination(candidates, i+1, R-candidates[i], comb)
                comb.pop(-1)
```
```c++ []
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int N = candidates.size();
        if(N == 0)
            return res;
        // sort
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        makeCombination(candidates, 0, target, comb);
        return res;
    }

private:
    void makeCombination(const vector<int> &candidates, int index, int R, vector<int> comb){
        if(R == 0){
            res.push_back(comb);
            return;
        }

        int E = INT32_MIN;
        for(int i=index; i<candidates.size(); ++i){
            if(R < 0)
                break;
            if(candidates[i] != E){
                E = candidates[i];
                comb.push_back(candidates[i]);
                makeCombination(candidates, i+1, R-candidates[i], comb);
                comb.pop_back();
            }
        }
    }

private:
    vector<vector<int>> res;
};
```