#### 解题思路：
只要找到链表的中间位置，以中间位置为分界线，反转前半部分，再用反转了的前半部分与后半部分做对比，如有不同就返回 false。
这一种做法虽然有两次遍历，但两次遍历的长度均为链表个数的一半，所以达到时间复杂度为 $O(n)$。

#### 获取中间值：
设置一个中间指针 mid，在一次遍历中，head 走两格，mid 走一格，当 head 取到最后一个值或者跳出时，mid 就指向中间的值。
```
let mid = head
// 循环条件：只要head存在则最少走一次
while(head !== null && head.next !== null) {
    head = head.next.next // 指针一次走两格
    mid = mid.next// 中间指针一次走一格
}
```

#### 反转前部分节点：
遍历的时候通过迭代来反转链表，mid 之前的 node 都会被反转。
使用迭代来反转。
```
while(head !== null && head.next !== null) {
        // 这个赋值要在mid被修改前提前
        pre = mid
        // 遍历链表
        mid = mid.next
        head = head.next.next
        // 反转前面部分的节点，并用reversed保存
        pre.next = reversed
        reversed = pre
    }
```

#### 注意：
奇数偶数的情况略有不同，奇数情况下，在判断值是否相同时 mid 要往后走一位。

例如：
奇数：1 -> 2 -> 3 -> 2 ->1
遍历完成后：mid = 3->2->1
           reversed = 2->1

偶数：1 -> 2 -> 2 ->1
遍历完成后：mid = 2->1
           reversed = 2->1


#### 完整代码如下：
```js []
var isPalindrome = function(head) {
    if(head === null || head.next === null) return true;
    let mid = head;
    let pre = null;
    let reversed = null;
    // end每次走两格，这个循环的时间复杂度为O(n/2)
    while(head !== null && head.next !== null) {
        // 这个赋值要在mid被修改前提前
        pre = mid
        // 遍历链表
        mid = mid.next
        head = head.next.next
        // 反转前面部分的节点，并用reversed保存
        pre.next = reversed
        reversed = pre
    }
    // 奇数mid往后走一位
    if(head) mid = mid.next
    while(mid) {
        if(reversed.val !== mid.val) return false
        reversed = reversed.next
        mid = mid.next
    }
    return true
};
```
