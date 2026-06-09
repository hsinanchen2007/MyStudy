
## 介绍
对于一个集合,他的幂集的个数(准确说幂集的元素个数)时 2 ^ n个,所以对于一开始我们假设nums中有n个元素,那么他的幂集的数量规模就是有n-1个元素的nums的二倍,我们举一个例子
```
加入一开始nums = [1,2,3],我们可以知道他的幂集是[[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]],然后它的元素个数就是nums = [1,2]的时候的幂集的个数的两倍,我们也可以知道nums = [1,2]的时候他的幂集是[[1],[2],[1,2],[]],针对这个,我们就可以猜想是否可以利用前一个集合的幂集来创建另外一个集合的幂集?
经过观测我们可以发现,对于nums = [1,2]的时候他的幂集[[1],[2],[1,2],[]],我们针对他的每一个元素,我们保留这个元素,然后复制它,再对复制的稍微改动,就变成了nums = [1,2,3]的时候的幂集,例如
- [1]我们保留[1],然后在[1]中push_back(3),这样就得到了[1]和[1,3]
- [2]我们保留[2],然后在[2]中push_back(3),这样就得到了[2]和[2,3]
- [1,2]我们保留[1,2],然后在[1,2]中push_back(3),这样就得到了[1,2]和[1,2,3]
- []我们保留[],然后在[]中push_back(3),这样就得到了[]和[3]
最后将这些汇总起来就得到了nums = [1,2,3]的时候的幂集
```
这就是我们需要递归的时候知道的规律,,从nums中有n个元素一直递归到nums中只有一个元素,.然后利用这个元素来构造
## 代码(无注释)
```cpp
class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int length1 = nums.size();
        vector<vector<int>> ans;
        if(length1 == 0){
            ans.push_back(vector<int>());
            return ans;
        }
        if(length1 == 1){
            ans.push_back(vector<int>());
            ans.push_back(vector<int>());
            ans[0].push_back(nums[0]);
            return ans;
        }
        int popnum = nums[nums.size()-1];
        nums.pop_back();
        ans = subsets(nums);
    
        int length = pow(2,length1-1);
        for(int i = 0;i<length;i++){
            ans.push_back(vector<int>());
            for(int j = 0;j<ans[i].size();j++){
                ans[i+length].push_back(ans[i][j]);
            }
            ans[i+length].push_back(popnum);
        } 
        return ans;
    }
};
```