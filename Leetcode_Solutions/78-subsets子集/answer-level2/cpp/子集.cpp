### 解题思路
首先给二维数组（res）存储一个空的一维数组，每添加一个元素，二维数组都要在原来的基础上增加相应的一维数组：一位数组的求取方式就是（遍历上一层的二维数组的每一个一维数组，将这个一维数组添加新的上面的元素即可）


举例子
初始    二维数组为  {[]} 
  添加第一个元素1   {[],[1]}               //[1]这个是由一维数组[].push_back(1)得来的
  添加第二个元素2   {[],[1],[2],[1,2]}     //[2]是[].push_back(2)得来的,[1,2]是由[1].push_back(2)得来的
  添加第三个元素3    .....              可以自己试一下继续推算  
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> res;
           vector<vector<int>> temp;
        res.push_back(t);
        cout<<res.size();
        for(int i=0;i<nums.size();i++)
        {
           // a.push_back(nums[i]);
          //  cout<<res.size()<<endl;
            temp=res;
            for(int j=0;j<temp.size();j++)
            { 
               // vector<int> t；
                    t=res[j];
                t.push_back(nums[i]);
                res.push_back(t);
                t.clear();
            }     
            
        }
        return res;
    }
};
```