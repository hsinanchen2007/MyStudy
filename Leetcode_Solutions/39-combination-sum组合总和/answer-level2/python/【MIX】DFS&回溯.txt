### 解题思路
dfs求解, 加入边界判断

### 代码

```java []
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        res = new ArrayList<>();
        if(candidates == null)
            return res;

        // 排序
        Arrays.sort(candidates);
        ArrayList<Integer> comb = new ArrayList<>();
        makeCombination(candidates, 0, target, comb);
        return res;
    }

    private void makeCombination(int []candidates, int index, int R, ArrayList<Integer> comb){
        // 递归的入口
        if(R == 0){
            this.res.add(new ArrayList<Integer>(comb));
            return;
        }

        // 递归&回溯&参数检测
        for(int i=index; i<candidates.length; ++i){
            if(R < 0)
                break;
            comb.add(candidates[i]);
            makeCombination(candidates, i, R-candidates[i], comb);
            comb.remove(comb.size()-1);
        }
    }

    private List<List<Integer>> res;
}
```
```python []
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates = list(set(candidates))
        N = len(candidates)
        comb = []
        self.res = []
        self.makeCombination(candidates, target, 0, comb)
        return self.res

    def makeCombination(self, candidates, R, index, comb):
        if R == 0:
            self.res.append(list(comb))
            return
        
        for i in range(index, len(candidates)):
            if R < 0:
                break
            comb.append(candidates[i])
            self.makeCombination(candidates, R-candidates[i], i, comb)
            comb.pop(-1)
```
```c++ []
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int N = candidates.size();
        if(N == 0)
            return res;

        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        makeCombination(candidates, 0, target, comb);

        return res;
        
    }

private:
    void makeCombination(const vector<int> &candidates, int index, int R, vector<int> comb){
        if(R == 0)
            res.push_back(comb);

        // 递归&回溯&去重
        for(int i=index; i<candidates.size(); ++i){
            if(R < 0)
                break;
            if(i!=0 && candidates[i]==candidates[i-1])
                continue;
            comb.push_back(candidates[i]);
            makeCombination(candidates, i, R-candidates[i], comb);
            comb.pop_back();
        }
    }

private:
    vector<vector<int>> res;
};
```