
## 2.两数相加
---
### 思路
将链表对应项按位相加，结果插在新链表`list`上。设定进位标志符`flag`，当某一位计算结果大于10时，该位置对10取余（或减10），并将`flag = true`，在下次运算时将进位加到结果上。

*需要注意*
1. 一个列表到了尾部另一个列表还没结束遍历的情况
2. 循环后需要再单独判断一下**最后一位是否需要进位**
3. 处理头节点
### 代码
```JavaScript
var addTwoNumbers = function(l1, l2) {

    let list = new ListNode('head');
    let flag = false;
    let result = list;

    while (l1 || l2) {

        let r = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + (flag ? 1 : 0);
        flag = r >= 10;

        result.next = new ListNode(r % 10);
        result = result.next;

        l1 = l1 ? l1.next : l1;
        l2 = l2 ? l2.next : l2;

    }

    result.next = flag ? new ListNode(1) : null;
    
    return list.next; //指向头节点的next即位我们的结果
};
```

### 复杂度分析
时间复杂度：$O(max(m,n))$ 需要遍历完最长的链表才能完成所有操作
空间复杂度：$O(max(m,n))$ 新生成的链表长度最大为 $max(m,n) + 1$ 
<br>

![image.png](https://pic.leetcode-cn.com/8e2a0c6d8c2feb575e397f3c4881d331d7d314a37312d56278a1d2d2c9c9f563-image.png)

