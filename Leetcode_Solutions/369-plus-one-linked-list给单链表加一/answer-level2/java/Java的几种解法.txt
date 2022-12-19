### 递归解法

本题用递归求解可以拆分为以下几个步骤：
1. 定义递归函数`p`，传入单个节点`h`给`p`
2. 如果`h`是尾巴节点，或对`h.next`的调用返回存在进位，那么对`h`的值进行修改，并判断是否存在进位，返回给上层递归调用
3. 当递归调用返回到头结点`head`时，若存在进位，则新建头节点`new_head`，指向`head`，并返回`new_head`，反之直接返回`head`即可

```
class Solution {
    public ListNode plusOne(ListNode head) {
        if(p(head)){
            ListNode new_head = new ListNode(1);
            new_head.next = head;
            return new_head;
        }else return head;
    }

    public boolean p(ListNode h){
        if(h.next == null || p(h.next)){
            int tmp = h.val + 1;
            h.val = tmp < 10? tmp:0;
            return !(tmp < 10);
        }
        return false;
    }
}
```

### 其他解法

 - 快慢指针（这个解法真牛逼）：https://leetcode-cn.com/problems/plus-one-linked-list/solution/c-kuai-man-zhi-zhen-bu-fan-zhuan-lian-biao-by-kao-/
 - 遍历法：https://leetcode-cn.com/problems/plus-one-linked-list/solution/liang-ci-bian-li-lian-biao-fei-di-gui-jie-fa-by-sh/
