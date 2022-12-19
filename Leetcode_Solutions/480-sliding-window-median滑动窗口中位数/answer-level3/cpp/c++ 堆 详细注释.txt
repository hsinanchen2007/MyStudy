### 解题思路
见代码

### 代码

```cpp
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int ka) {
        vector<double> ans;
        priority_queue<int,vector<int>,less<int>> leftque;
        priority_queue<int,vector<int>,greater<int>> rightque;
        unordered_map<int,int>ump;
        //初始化操作
        int i = 0;
        while(i < ka)
        {
            leftque.push(nums[i++]);
        }
        int right = i;
        i = 0;
        while(i < ka / 2)
        {
            rightque.push(leftque.top());
            leftque.pop();
            i++;
        }
        while(right <= nums.size())
        {
            //如果k是奇数
            if(ka & 1)
            {
                ans.push_back((double)leftque.top());
            }
            //k是偶数
            else
            {
                ans.push_back(((double)leftque.top() + (double)rightque.top()) / 2.0);
            }   
            //结束条件
            if(right >= nums.size()) break;

            int out_num = nums[right - ka];
            int in_num = nums[right];
            right++;
            int balance = 0;
            //记录删除的out_num
            ump[out_num]++;
            //根据out_num决定balance
            if(out_num <= leftque.top())
            {
                balance--;
            }
            else
            {
                balance++;
            }
            //根据in_num决定balance
            //为什么是if不是while 因为每次最多改变了两个元素（in_sum 和 out_sum）,而push和pop会
            //改变这两个。
            if( leftque.empty() || in_num <= leftque.top())
            {
                balance++;
                leftque.push(in_num);
            }
            else
            {
                balance--;
                rightque.push(in_num);
            }

            //根据balance调整堆
            if(balance < 0)
            {
                leftque.push(rightque.top());
                balance++;
                rightque.pop();
            }
            //一定要写 > 0 而不是 else
            if(balance > 0)
            {
                rightque.push(leftque.top());
                balance--;
                leftque.pop();
            }

            //查看map 是否删除堆顶元素
            while(!leftque.empty() && ump[leftque.top()])
            {
                ump[leftque.top()]--;
                leftque.pop();
            }

            while(!rightque.empty() && ump[rightque.top()])
            {
                ump[rightque.top()]--;
                rightque.pop();
            }
        }
        return ans;
    }
};
```