### 解题思路
思路和全排列II类似, 加入去重的操作

### 代码

```java []
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        // 从Subsets I的角度开始考虑
        this.res = new ArrayList<>();
        if(nums==null || nums.length==0)
            return res;

        // 排序, 为递归算法中的去重做铺垫
        Arrays.sort(nums);

        ArrayList<Integer> subset = new ArrayList<>();
        subSetHelper(nums, 0, subset);
        return this.res;

    }

    private void subSetHelper(int[] nums, int index, ArrayList<Integer> subset){
        this.res.add(new ArrayList<>(subset));
        int E = Integer.MAX_VALUE;
        for(int i = index; i<nums.length; ++i){
            if(nums[i] != E){
                subset.add(nums[i]);
                E = nums[i];
                subSetHelper(nums, i+1, subset);
                subset.remove(subset.size()-1);
            }
        }
    }

    private List<List<Integer>> res;
}
```
```python []
class Solution:
    def __init__(self):
        self.res = []

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        if nums==None or len(nums) == 0:
            return []
        
        nums.sort()
        subset = []
        self.subSetHelper(nums, 0, subset) 
        return self.res

    def subSetHelper(self, nums, index, subset):
        self.res.append(list(subset))

        E = float('inf')
        for i in range(index, len(nums)):
            if nums[i] != E:
                E = nums[i]
                subset.append(E)
                self.subSetHelper(nums, i+1, subset)
                subset.pop(-1)
```
```c++ []
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return res;

        // sort
        sort(nums.begin(), nums.end());
        vector<int> subset;
        subSetHelper(nums, 0, subset);
        return this->res;
    }

private:
    void subSetHelper(const vector<int>& nums, int index, vector<int>& subset){
        this->res.push_back(subset);
        int E = INT32_MAX;
        for(int i=index; i<nums.size(); ++i){
            if(nums[i] != E){
                subset.push_back(nums[i]);
                E = nums[i];
                subSetHelper(nums, i+1, subset);
                subset.pop_back();
            }
        }
    }

private:
    vector<vector<int>> res;
};
```