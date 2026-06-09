### 解题思路
双重循环暴力解题：外层表示第一个数，内层找第二个数。
### 知识点
1.在判断bool值a为真或为假时：使用if(!a)或if(a)(这里我之前是用的a==true但是这种做法在leetcode中不行)。
2.vector初始化的一种方法：vector<int> a={a,b,c,d};这里a,b,c,d指的是vector初值。
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //先将数组排序，这样比target大的就可以直接排除（错误！！因为整数可能为负数
        //双重循环
        int i,j;
        int second=0;
        bool find=false;
        for(i=0;i<nums.size()&&!find;++i){//错误点1“find==true”
            second=target-nums[i];
            for(j=i+1;j<nums.size();++j){
                if(nums[j]==second){
                    find=true;
                    break;
                }
            }
        }
        i--;
        //输出
        vector<int> ans={i,j};
        return ans;
    }
};
```