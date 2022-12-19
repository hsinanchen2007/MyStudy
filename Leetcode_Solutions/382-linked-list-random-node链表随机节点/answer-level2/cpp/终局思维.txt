查了半天蓄水池采样的资料，看的一脸懵。
很多材料上来就告诉你第 `i` 个节点要以`1/i` 概率选取，然后再去证明这个值是对的。
但问题是我要怎么想到这个值呢？
这时候就要用到终局思维了：当走到最后一个节点 `n` 时，要保证最后一个节点被选取概率是`1/n`，
那么这时就以`1/n` 概率选取这个值，并替换当前值。
这时候再往前推一步，要保证 `n-1`最终被选取的概率是`1/n`，那么当走到`n-1`时，要以什么概率选取？
假设这个概率是 `x`，那么 `n-1`最终被选取的概率就是`x * (1-1/n)`，其含义就是，`n-1`被选到，并且`n`没被选到，
那么最终留下的就是 `n-1`的值。
那么我们就推出来 `x * (1-1/n) == 1/n`，`x` 的值就是`1/n-1`。有没有霍然开朗的感觉？
以上思维方式，也可以推广到选取 `k` 个，稍微一点改变是，在看 `n-1`最终是否被保留下来时，等式是
`x * (1-k/n * 1/k) == k / n`，`k/n * 1/k`的含义是 `n`被选取了，并且将集合中的 `n-1`给替换掉了(概率就是从 k 个里选1个），
再解释一下就是： `n-1`先被以 `x` 的概率选取，而后又被 `n`替换掉。
因此`n-1`最终保留在集合中的概率就是 `x - x * k/n * 1/k`，这个概率要等于 `k/n`。

有了以上推导，终于能放心的使用`1/i` 这个概率值选取第 `i` 个节点了。代码很简单。

```c++
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): head(head) {

    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i=2;
        ListNode* cur = head->next;
        int val = head->val;
        while(cur != nullptr) {
            if(rand() % i + 1 == 1) val = cur->val; //第 i 节点以 1/i 概率替换当前值
            i++;
            cur = cur->next;
        }
        return val;
    }
private:
    ListNode* head;
};
```