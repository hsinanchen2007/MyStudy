### 解题思路
1、借助数组 仅需遍历一次链表

### 代码

```cpp

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {

        //将链表放入数组中
        vector<ListNode*> v;
        ListNode* cur = root;
        while (cur)
        {
            v.push_back(cur);
            cur = cur->next;
        }

        int count = v.size() / k; // 每份个数
        int remainder = v.size() % k; //余数

        //使用数组分割，设置终止nullptr, 并放入结果数组
        vector<ListNode*> res;
        v.reserve(k);

        //每组的start index：i * count + i 、end index：(i + 1) * count + i
        for (int i = 0; i < remainder; ++i) //如果余数 > 0，则前余数份，每份为count + 1个
        {
            res.push_back(v.at(i * count + i));
            v.at((i + 1) * count + i)->next = nullptr;
        }

        int index = remainder * (count + 1);
        for (int i = 0; i < k - remainder; ++i) //后面的k - 余数份，每份为count个
        {
            if (count == 0)
            {
                res.push_back(nullptr);
            }
            else
            {
                res.push_back(v.at(index));
                v.at(index + count - 1)->next = nullptr; //count个
                index += count;
            }
        }

        return res;
    }
};
```