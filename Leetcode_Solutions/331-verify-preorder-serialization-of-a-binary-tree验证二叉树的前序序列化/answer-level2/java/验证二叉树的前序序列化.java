#### 方法一：迭代

**思路**

首先不考虑最优性，从最简单的解法来讨论这个问题。

我们可以定义一个概念，叫做槽位，二叉树中任意一个节点或者空孩子节点都要占据一个槽位。二叉树的建立也伴随着槽位数量的变化。开始时只有一个槽位，如果根节点是空节点，就只消耗掉一个槽位，如果根节点不是空节点，除了消耗一个槽位，还要为孩子节点增加两个新的槽位。之后的节点也是同理。
 
> 有了上面的讨论，方法就很简单了。依次遍历前序序列化，根据节点是否为空，按照规则消耗/增加槽位。如果最后可以将所有的槽位消耗完，那么这个前序序列化就是合法的。

- 开始时只有一个可用槽位。

- 空节点和非空节点都消耗一个槽位。

- 空节点不增加槽位，非空节点增加两个槽位。

![fig](https://pic.leetcode-cn.com/Figures/331/rules.png)

**算法**

- 初始化可用槽位：`slots = 1`。

- 根据逗号分隔前序序列化，将结果数组存储，随后遍历该数组：

    - 空节点和非空节点都消耗一个槽位：`slots = slot - 1`.
    
    - 如果当前的可用槽位是负数，那么这个前序序列化是非法的，返回 False。
    
    - 非空节点（`node != '#'`）新增两个可用槽位：`slots = slots + 2`.
    
- 如果所有的槽位都消耗完，那么这个前序序列化就是合法的：返回 `slots == 0`。

**实现**

```python [solution1-Python]
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        # number of available slots
        slots = 1

        for node in preorder.split(','):
            # one node takes one slot
            slots -= 1
            
            # no more slots available
            if slots < 0:
                return False
            
            # non-empty node creates two children slots
            if node != '#':
                slots += 2
        
        # all slots should be used up
        return slots == 0
```

```java [solution1-Java]
class Solution {
  public boolean isValidSerialization(String preorder) {
    // number of available slots
    int slots = 1;

    for(String node : preorder.split(",")) {
      // one node takes one slot
      --slots;

      // no more slots available
      if (slots < 0) return false;

      // non-empty node creates two children slots
      if (!node.equals("#")) slots += 2;
    }

    // all slots should be used up
    return slots == 0;
  }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 N 为字符串的长度。

* 空间复杂度：$O(N)$。
 
#### 方法二：一遍过

**思路**

方法一需要用到 $O(N)$ 的空间来存储前序序列化分割之后的结果数组，但我们可以直接遍历前序序列化字符串，这样就不用开辟额外空间了。

在遍历过程中，每遇到逗号字符就更新可用槽位的数量。首先，将槽位减一（空节点和非空节点都要消耗一个槽位）。其次，如果当前节点是非空节点（即逗号字符前不是 `#`），新增两个槽位。

需要注意的是，最后一个节点需要单独处理，因为最后一个节点后面没有逗号字符。

<![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_1.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_2.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_3.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_4.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_5.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_6.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_7.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_8.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_9.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_10.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_11.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_12.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_13.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_14.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_15.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_16.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_17.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_18.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_19.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_20.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_21.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_22.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_23.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_24.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_25.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_26.png),![1200](https://pic.leetcode-cn.com/Figures/331/331_slide_27.png)>

**算法**

- 初始化可用槽位为 1：`slots = 1`。

- 遍历前序序列化字符串，每遍历到逗号字符：

    - 空节点和非空节点都消耗一个槽位：`slots = slot - 1`。
    
    - 如果当前可用槽位是负数，那么这个先序序列就是非法的，返回 False。
    
    - 非空节点（即逗号字符前不是 `#`），新增两个可用槽位：slots = slots + 2`。
    
- 最后一个节点需要单独处理，因为最后一个节点后面是没有逗号的。

- 如果可用槽位全部被消耗完，那么该前序序列化就是合法的：返回 `slots == 0`。

**实现**

```python [solution2-Python]
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        # number of available slots
        slots = 1
        
        prev = None  # previous character
        for ch in preorder:
            if ch == ',':
                # one node takes one slot
                slots -= 1

                # no more slots available
                if slots < 0:
                    return False

                # non-empty node creates two children slots
                if prev != '#':
                    slots += 2
            prev = ch
        
        # the last node
        slots = slots + 1 if ch != '#' else slots - 1 
        # all slots should be used up
        return slots == 0
```

```java [solution2-Java]
class Solution {
  public boolean isValidSerialization(String preorder) {
    // number of available slots
    int slots = 1;

    int n = preorder.length();
    for(int i = 0; i < n; ++i) {
      if (preorder.charAt(i) == ',') {
        // one node takes one slot
        --slots;

        // no more slots available
        if (slots < 0) return false;

        // non-empty node creates two children slots
        if (preorder.charAt(i - 1) != '#') slots += 2;
      }
    }

    // the last node
    slots = (preorder.charAt(n - 1) == '#') ? slots - 1 : slots + 1;
    // all slots should be used up
    return slots == 0;
  }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 N 为字符串的长度。

* 空间复杂度：$O(1)$，只占用常数空间。