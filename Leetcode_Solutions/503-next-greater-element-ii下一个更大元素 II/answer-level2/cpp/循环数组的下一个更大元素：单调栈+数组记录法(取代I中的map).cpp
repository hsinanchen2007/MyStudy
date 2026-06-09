### 解题思路
此处撰写解题思路
注意：
（1）循环数组入栈两次；
（2）第二次循环时不入栈的条件：已经有这条记录了；
（3）数据可能为负数，因为这个原因错了一次。
性能：用时78%，空间85%

### 代码

```cpp
#include<vector>
#include<stack>
#include<map>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //依然采用单调栈的方法
        //consider the difference:
        //（1）入栈是为了今后找到下一个更大的元素；故而一个元素是否入栈，关键在于看它是否能在map中find不到
        //（2）由于是循环数组，得反复入栈，那末何时终止呢？
        //      终止的时候，栈中必有一个或多个最大元素;
        //      粗暴的方法，扫描两遍
        //（3）不能使用map，因为循环中有多个相同元素，or采用下标作为index
        //（4）本题已经没有使用map的需求，直接下标
        
        //测试用例不能为-1，但却可能为-2，坑...

        stack<pair<int, int>> oneDStk; //first:index, second:value
        vector<int> resVec(nums.size(), 0);  //-2代表未计算，已经取消
        vector<bool> isInitial(nums.size(),true);
        //bool* isInitial = new bool[nums.size()](true);
        for(int i = 0; i < 2*nums.size(); i++){
            int j = i % nums.size();
            while(!oneDStk.empty() && nums[j] > oneDStk.top().second){
                resVec[oneDStk.top().first] = nums[j];
                isInitial[oneDStk.top().first] = false;
                oneDStk.pop();
            }
            if(true == isInitial[j]){
                oneDStk.push(pair(j,nums[j]));
            }
        }

        while(!oneDStk.empty()){
            resVec[oneDStk.top().first] = -1;
            oneDStk.pop();
        }

        return resVec;


    }
};
```