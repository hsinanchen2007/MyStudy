### 解题思路
递归&回溯

### 代码

```java []
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums == null || nums.length==0)
            return res;
        // 排序
        Arrays.sort(nums);
        
        // 递归+回溯
        ArrayList<Integer> subset = new ArrayList<>();
        subSetHelper(nums, 0, subset, res);
        return res;
    }

    private void subSetHelper(int []nums, int index, ArrayList<Integer> subset, List<List<Integer>> res){
        // deep copy subset
        res.add(new ArrayList<Integer>(subset));

        for(int i=index; i< nums.length; ++i){
            subset.add(nums[i]);
            subSetHelper(nums, i+1, subset, res);
            subset.remove(subset.size()-1);
        }
    }
}
```
```python []
class Solution:
    def __init__(self):
        self.res = []

    def subsets(self, nums: List[int]) -> List[List[int]]:
        if nums == None or len(nums) == 0:
            return self.res

        subset = []
        self.subSetHelper(nums, 0, subset)
        return self.res

    def subSetHelper(self, nums, index, subset):
        self.res.append(list(subset))
        for i in range(index, len(nums)):
            subset.append(nums[i])
            self.subSetHelper(nums, i+1, subset)
            subset.pop(-1)
```
```c++ []
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0)
            return this->res;

        vector<int> subset;
        subSetHelper(nums, 0, subset);
        return this->res;    
    }

private:
    void subSetHelper(const vector<int>& nums, int index, vector<int>& subset){
        this->res.push_back(subset);
        for(int i=index; i<nums.size(); ++i){
            subset.push_back(nums[i]);
            subSetHelper(nums, i+1, subset);
            subset.pop_back();
        }
    }

private:
    vector<vector<int>> res;

};
```
