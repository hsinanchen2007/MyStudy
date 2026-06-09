
// 题目要求的是**从尾到头**。这种“后进先出”的访问顺序，自然想到了用栈。

// 时间复杂度 O(N)，空间复杂度 O(N)。

// ```javascript
// ac地址：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
// 原文地址：https://xxoo521.com/2019-12-21-da-yin-lian-biao/

/**
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrint = function(head) {
    const stack = [];
    let node = head;
    while (node) {
        stack.push(node.val);
        node = node.next;
    }

    const reverse = [];
    while (stack.length) {
        reverse.push(stack.pop());
    }

    return reverse;
};
// ```

// 发现后半段出栈的逻辑，其实就是将数组`reverse`反转。因此，借助 javascript 的 api，更优雅的写法如下：

// ```javascript
// ac地址：https://www.***.com/practice/d0267f7f55b3412ba93bd35cfa8e8035
// 原文地址：https://xxoo521.com/2019-12-21-da-yin-lian-biao/

/**
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrint = function(head) {
    const stack = [];
    let node = head;
    while (node) {
        stack.push(node.val);
        node = node.next;
    }
    return stack.reverse();
};
// ```

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
