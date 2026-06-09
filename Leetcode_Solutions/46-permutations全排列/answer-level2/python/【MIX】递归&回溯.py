### 解题思路
使用辅助数组+递归回溯搜索

### 代码

```java []
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        // 递归&回溯
        res = new ArrayList<>();
        if(nums.length == 0)
            return res;
        used = new boolean[nums.length];
        // 初始化状态数组
        for(int i=0; i<nums.length; ++i){
            used[i] = false;
        }

        ArrayList<Integer> arr = new ArrayList<>();
        makePermutation(nums, 0, arr);
        return this.res;
    }

    // p{index+1} = p{index}+p{1}, {index}表示长度为index的排列
    private void makePermutation(int[] nums, int index, ArrayList<Integer> p){
        if(index == nums.length){
            // 需要调用一下构造函数
            res.add(new ArrayList<>(p));
            return;
        }
        for(int i=0; i<nums.length; ++i){
            if(!used[i]){
                p.add(nums[i]);
                used[i] = true;
                makePermutation(nums, index+1, p);
                // 回溯
                p.remove(p.size()-1);
                used[i] = false;
            }
        }
    }

    private List<List<Integer>> res;
    // 状态数组
    private boolean []used;
}
```
```python []
class Solution:
    # 使用库函数
    def permute(self, nums: List[int]) -> List[List[int]]:
        return [*itertools.permutations(nums)]
```
```python []
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # 递归+回溯
        if len(nums) == 0:
            return []

        self.res = []
        self.used = [False for _ in range(len(nums))]
        p = []
        self.__make_permutation(nums, 0, p)
        return self.res

    def __make_permutation(self, nums, index, p):
        if index == len(nums):
            self.res.append(list(p))
            return

        for i in range(len(nums)):
            if self.used[i] is False:
                p.append(nums[i])
                self.used[i] = True
                # 递归
                self.__make_permutation(nums, index+1, p)
                # 回溯
                p.pop()
                self.used[i] = False
```
```c++ []
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        if(nums.size() == 0)
            return res;
        used = vector<bool>(nums.size(), false);
        makePermutation(nums, 0, vec);
        return this->res;        
    }

private:
    // permu[index+1] = p[index]+p[1]
    void makePermutation(const vector<int>& nums, int index, vector<int>& p){
        if(index == nums.size()){
            res.push_back(p);
        }
        
        for(int i=0; i<nums.size(); ++i){
            if(!used[i]){
                p.push_back(nums[i]);
                used[i] = true;
                makePermutation(nums, index+1, p);
                // 退格当前加入的元素
                p.pop_back();
                used[i] = false;
            }
        }
    }

private:
    vector<vector<int>> res;
    vector<bool> used;
};
```
**2020/4/9**
```c++ []
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return res;
        vector<int> P;
        used = vector<bool>(N, false);
        makePermutation(nums, 0, N, P); // 对index位放置元素nums[i]进行递归回溯
        return res;
    }

private:
    void makePermutation(const vector<int> &nums, int index, int N, vector<int> P){
        if(index == N)
            res.push_back(P);
        
        for(int i=0; i<N; ++i){
            if(!used[i]){
                used[i]=true;
                P.push_back(nums[i]);
                makePermutation(nums, index+1, N, P);
                // 回溯
                P.pop_back();
                used[i] = false;
            }
        }
    }

    vector<bool> used;
    vector<vector<int>> res;
};
```