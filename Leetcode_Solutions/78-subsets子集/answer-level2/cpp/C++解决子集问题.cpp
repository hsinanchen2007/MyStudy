### 解题思路
使用了dfs的思想设置标志位，通过递归来实现子集的选择和加入结果数组

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { //定义初始数组nums
        vector<vector<int>> ans;  //定义返回二维数组结果
        vector<int> cur; //定义当前的子集
        for(int i=0;i<=nums.size();i++)  //循环遍历初始数组nums
        dfs(nums,i,0,cur,ans);//定义递归函数dfs nums:输入数组，i:循环变量，0：开始标志位，cur:当前子集，ans:结果二维数组
        return ans;//返回二维数组结果

    }
private:
    void dfs(const vector<int>& nums,int n,int s,vector<int>& cur,vector<vector<int>>& ans){
        if(n==cur.size()){ //边界条件：当开始标志位等于当前子集的末尾时
          ans.push_back(cur);//将当前的子集添加到最终的结果当中
          return;//无返回值
        }
        for(int i=s;i<nums.size();i++){  //从标志位开始遍历初始数组
            cur.push_back(nums[i]);//将当前遍历的数组元素加入子集中
            dfs(nums,n,i+1,cur,ans);//递归调用dfs对从i+1标志位开始的元素进行子集操作
            cur.pop_back();//将子集弹出
        }
    }
};
```