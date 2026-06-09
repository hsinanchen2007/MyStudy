**首先**是非递归DFS做中序遍历，要熟练的写出来：
```cpp
deque<TreeNode*> dq;
TreeNode* cur = root;
while(cur!=NULL || !dq.empty()) {
    if(cur!=NULL) {
        dq.push_back(cur);
        cur = cur->left;
    }
    else {
        cur = dq.back(); //我用的deque，这里容易写成front()导致出错。。
        dq.pop_back();

        //do sth for cur

        cur = cur->right;
    }
}
```

**其次**是用两个变量做标记的思路。
这里第一次想的时候，出错了。
这里的目的在于push back元素到res，需要考虑的是：
- 1.不是众数的元素，不要push back。这个比较容易避开，因为对应元素的cur_times小于max_times
- 2.是众数的元素，需要push back。这个也容易想到。只要cur_times>=max_times就执行。
- 3.同一个众数元素，只应该push back一次。这个容易漏掉。如何确保呢？

把2和3结合起来看，应该在cur_time==max_times的时候push back，
而cur_time>max_times的时候，先clear，再push back，这就确保了只push back一个。

而为了准确的push back，就需要提前处理更新好cur_times。

最后，记得更新max_times，以及前一个节点prev。


```cpp
class Solution {
public:
    vector<int> findMode(TreeNode* root) {

        vector<int> res;
        if (root == NULL) return res;

        TreeNode* cur = root;
        deque<TreeNode*> dq;
        TreeNode* prev = NULL;

        int max_times = 0;
        int cur_times = 1;
        while (cur != NULL || !dq.empty()) {
            if (cur != NULL) {
                dq.push_back(cur);
                cur = cur->left;
            }
            else {
                cur = dq.back();
                dq.pop_back();

                if (prev != NULL) {
                    if (prev->val == cur->val) {
                        cur_times++;
                    }
                    else {
                        cur_times = 1;
                    }
                }

                if (cur_times == max_times) {
                    res.push_back(cur->val);
                }
                else if (cur_times > max_times) {
                    res.clear();
                    res.push_back(cur->val);
                    max_times = cur_times;
                }

                prev = cur;

                cur = cur->right;
            }
        }

        return res;
    }
};
```