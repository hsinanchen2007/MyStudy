### 解题思路
首先用sort函数对candidates排序
然后深度遍历，每趟累加结果，当等于target时存入二维数组。（具体看下面注释）



#### 注意：需要剪枝（如下图）
![捕获.JPG](https://pic.leetcode-cn.com/3cbb891fa5de4e3fe8e35c7213aef60d071b70232909b91353666fd573b2dd53-%E6%8D%95%E8%8E%B7.JPG)

而且每趟遍历选数只能往后选，如果每趟都从头开始遍就会导致同一结果出现不同的排列组合，不合题意。
【即每趟遍历开始值为  j+abs(i-j)，解释在下面】


### AC代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> s;
        sort(candidates.begin(),candidates.end());      //对candidates进行排序
        dfs(result,s,candidates,0,target,0); //依次为（目标数组，存放一组结果的一维数组，candidates，当前和，目标值，需要从哪里开始遍历的标记变量）
        return result;
    }
    void dfs(vector<vector<int>>& r, vector<int>& s,vector<int>& c,int sum,int t,int j)
    {
        if(sum==t)
        {
            r.push_back(s);         //与目标值相等则把 一维数组 存入目标数组
            return;
        }
        for(int i=j;i<c.size();i++)     //注意i从j开始
        {
            if(sum+c[i]<=t)
            {   
                s.push_back(c[i]);          //放进一维数组
                sum+=c[i];                  //求当前和
                dfs(r,s,c,sum,t,j+abs(i-j));  //注意：标记变量的值是 j+abs(i-j)，为什么？只能有两种情况1：下一个选数也跟当前的c[i]相同，则可以从 j 开始； 情况2：下一个选数只能在当前数的后面，则只能从 j+abs(i-j) 开始。
                s.pop_back();               //回溯
                sum-=c[i];
            }
            else            //因为已经对candidates排好序，所以如果sum+c[i]>target,则下标i后面的数加上去肯定大于target，需剪掉
            break;
        }
    }
};
```
![捕获.JPG](https://pic.leetcode-cn.com/ef49aeccfe85968c9e74b214bc3fac4dc2218646eeca14833cdae1488fca1fbd-%E6%8D%95%E8%8E%B7.JPG)
