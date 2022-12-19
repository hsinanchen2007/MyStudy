### 解题思路
方法1：直接找 时间复杂度O(N^2) 空间复杂度O(1)
方法2：单调栈 使用辅助数组 时间复杂度O(N) 空间复杂度O(N)
方法3：单调栈，不使用辅助数组，直接修改结果数组  时间复杂度O(N) 空间复杂度O(N)
### 代码

```cpp

class Solution {
public:

    //方法1：直接找 时间复杂度O(N^2)
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> v;

        ListNode* cur = head;

        while (cur)
        {
            ListNode* next = cur->next;
            while (next)
            {
                if (next->val > cur->val)
                {
                    v.push_back(next->val);
                    break;
                }
                next = next->next;
            }
            
            if(next == nullptr)
                v.push_back(0);

            cur = cur->next;
        }

        return v;
    }


    //方法2：单调栈 使用辅助数组  时间复杂度O(N) 空间复杂度O(N)
    vector<int> nextLargerNodes(ListNode* head) {

        //将链表放入数组
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        //使用单调递增栈，遇到比栈顶大的就要出栈
        vector<int> res(v.size());
        stack<int> stack;

        for (int i = 0; i < v.size(); ++i)
        {
            while (!stack.empty() && v.at(i) > v.at(stack.top()))
            {
                int index = stack.top();
                stack.pop();

                res.at(index) = v.at(i);
            }

            stack.push(i);
        }

        //res初始化全为0，可以不填了
        // while (!stack.empty())
        // {
        //     int index = stack.top();
        //     stack.pop();
        //     res.at(index) = 0; //都填0 没有比它大的
        // }

        return res;
    }


    //方法3：单调栈，不使用辅助数组，直接修改结果数组  时间复杂度O(N) 空间复杂度O(N)
    vector<int> nextLargerNodes(ListNode* head) {

        //将链表放入结果数组
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }

        stack<int> stack;

        //从右往左遍历
        for (int i = (int)res.size() - 1; i >= 0; --i)
        {
            int cur = res.at(i); //先暂存当前元素

            while (!stack.empty() && cur >= stack.top()) //注意: 等于号不能少 等于时也需要出栈 这里是找严格大于的数
            {
                stack.pop();  //淘汰小的 留下更大的
            }
            
            res.at(i) = (stack.empty() ? 0 : stack.top()); //栈空 右边没有更大的

            stack.push(cur);
        }

        return res;
    }
};
```