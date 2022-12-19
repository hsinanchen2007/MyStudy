![图片.png](https://pic.leetcode-cn.com/5aa44f7f374ee94f0ad98f8c247e8a58ab1d6f71aac843cddaf34daab2178bac-%E5%9B%BE%E7%89%87.png)

### 解题思路
画树状图配合理解，找好剪枝条件，配合回溯方法模板。

### 代码

```cpp
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> path;
        backtrack(path,k,n,1,0);
        return res;
    }
    //start表示下一个选择的起始位置，total表示已选择的数字求和
    void backtrack(vector<int> &path,const int &k,const int &n,const int &start,int total)
    {
        //结束条件
        if(total==n && path.size()==k)
        {
            res.push_back(path);
            return;
        }
        if(path.size() > k) return;
        for(int i=start;i<=9;i++)
        {
        //剪枝：主要思想是根据total的值和已经做的选择，如果将要选择的数字小于上一个选择，则不必向下遍历
            if((!path.empty()) && (n-total <= path.back())) break;
            if(total+i > n) break;

            path.push_back(i);
            total += i;

            backtrack(path,k,n,i+1,total);

            path.pop_back();
            total -= i;
        }
    }
};
```