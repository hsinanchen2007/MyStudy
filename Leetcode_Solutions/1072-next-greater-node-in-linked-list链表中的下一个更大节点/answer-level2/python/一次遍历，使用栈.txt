### 解题思路：
因为 `vector` 支持扩容，所以可以直接一边扫描一边 `push_back` 直接实现，基础为栈，思路比较简单
我的栈中存储的是元素的 `val` 和下标，每次出栈依靠下标去修改 `vector` 中的值，`val` 则用作比较大小

以示例 $2$ 为例：
`[2,7,4,3,5]`

![微信截图_20190529004233.png](https://pic.leetcode-cn.com/ee750c735dd42379383f4d3adf89a51ead063d4582e502abff0918f313e67285-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190529004233.png){:width=550}
{:align=center}


```cpp [-cpp]
class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        int count = 0; //计数，作为下标
        vector<int> result;
        stack<pair<int, int>> tmp; //first为val，second为下标
        while (head)
        {
            result.push_back(0); //给result数组后面+0，1为保证长度，2是默认值（后无更大的值的话）为0
            while (!tmp.empty() &&
                   head->val > tmp.top().first) //栈不为空且head指针的val值大于栈顶的元素的值
            {
                result[tmp.top().second] = head->val; //result数组修改，满足题意要求的最大值，然后出栈，继续循环
                tmp.pop();
            }
            tmp.push(make_pair(head->val, count++)); //count++计数
            head = head->next; //下一个节点
        }
        return result;
    }
};
```
