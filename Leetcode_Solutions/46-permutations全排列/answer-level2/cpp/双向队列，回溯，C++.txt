### 解题思路
此处撰写解题思路
89.53%  100.00%
回溯算法，用双向队列dq存储原始数据。取的时候从front取，加入的时候从back加入。
myfunc的处理步骤：在dq长为某个值时，进行其长度的遍历。每次遍历途中，从0下标取数据并pop头部数据（这样该遍历的下一次会依次取后面的数据，回溯调用该方法myfunc（此时dq长度减1），之后将该次取出的数据插入dq尾部。
在某次迭代途中，dq为0时表示形成了一次排序并放入结果中。
如：[1,2,3,4]一次迭代出1，2，3，4.然后把4插入后面（此时对应dq长度为1），再把3插入后面（此时长度为2，dq内容是[4,3]，会进行长度为2的第二次迭代得到1，2，4，3；再经过插入并回溯到长度为3的情况[1,3,4,2]）。
此方法结果中的顺序不是按每一位依次比较的字典序，但可将数据全排列出来。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.empty()){
            return res;
        }
        //回溯
        vector<int>pp;
        deque<int>dq;
        dq.assign(nums.begin(),nums.end());
        myfunc(res,dq,pp);
        return res;
    }
    void myfunc(vector<vector<int>>&res,deque<int>&dq,vector<int>&pp){
        if(dq.empty()){
            res.emplace_back(pp);
            return;
        }
        int len=dq.size();
        for(int i=0;i<len;i++){
            int tmp=dq[0];
            pp.emplace_back(tmp);
            dq.pop_front();
            myfunc(res,dq,pp);
            pp.pop_back();
            dq.emplace_back(tmp);
        }
    }
};
```