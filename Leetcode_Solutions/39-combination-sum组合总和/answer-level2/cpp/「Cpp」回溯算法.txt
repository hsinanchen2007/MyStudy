### 第三版

在循环体中剪枝，而不是之前在终止条件中过滤选择。

两者的区别是，对于数据集1,2,4,5,6, 我们的目标是2。我们选择1,1后，第二版代码还会继续循环体，也就是还会选择1,1,2 1,1,4。直接在循环体中剪枝，就可以把后面的都跳过。


```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        if (candidates.size() == 0) return res;

        DFS(candidates, comb,  0, 0,target);

        return res;
        

    }

    void DFS(vector<int>& candidates, vector<int>& comb, int last, int total, int target){
        if (total == target) {
            res.push_back(comb); 
            return; 
        }
            

        for (int i = last; i < candidates.size(); i++ ){
            if ( total + candidates[i] > target) continue;
            
            comb.push_back(candidates[i]);
            DFS(candidates, comb, i,  total +  candidates[i], target);
            comb.pop_back();
        }
        return ;
    }
};
```

### 第二版

不需要用set判定重复。因为数组没有重复元素。

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        if (candidates.size() == 0) return res;

        DFS(candidates, comb,  0, 0,target);

        return res;
        

    }

    void DFS(vector<int>& candidates, vector<int>& comb, int last, int total, int target){
        if ( total >= target ){
            if (total == target) {
                res.push_back(comb);  
            }
            return;
        }

        for (int i = last; i < candidates.size(); i++ ){
            comb.push_back(candidates[i]);
            total += candidates[i];
            DFS(candidates, comb, i,  total, target);
            total -= candidates[i];
            comb.pop_back();
        }
        return ;
    }
};
```

### 第一版 解题思路

因为可以重复选择，因此每次选择的元素可以和之前一样。

为了保证不重复，使用set存储每一次选择，最终输出的时候进行检查。（有其他更好的方法，）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> dict;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> comb;

        if (candidates.size() == 0) return res;
        sort(candidates.begin(), candidates.end()); //不排序，虽然输出结果一样，但是位置不一样，会认为是错误

        DFS(candidates, comb,  0, 0,target);

        return res;

    }

    void DFS(vector<int>& candidates, vector<int>& comb, int last, int total, int target){
        if ( total >= target ){
            if (total == target) {
                sort(comb.begin(), comb.end());
                if ( dict.find(comb) == dict.end()){
                    res.push_back(comb);
                    dict.insert(comb);
                }    
            }
            return;
        }

        for (int i = last; i < candidates.size(); i++ ){
            comb.push_back(candidates[i]);
            total += candidates[i];
            DFS(candidates, comb, i,  total, target);
            total -= candidates[i];
            comb.pop_back();
        }
        return ;
    }
};
```