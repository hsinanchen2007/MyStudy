0. 体悟：算法问题是人思考如何解决问题的具体实施步骤，对问题的不同理解，会带来完全不同的解决方案，思维之下是算法？欢迎一起探讨
1.  本质：删除链表的倒数第 n 个节点，对n不同理解存在不同的解题思路，两种理解方式：
    n是位置（倒数第 n 个节点在链表中所处的位置。解法1与2）
    n是距离（倒数第 n 个节点距离链表结尾的距离。解法3）
2. 倒数第N个节点，可以将链表反转，然后他的倒数也就是正数位置了，然后删除即可(这个比较笨哈)
```javascript []
var removeNthFromEnd = function(head, n) {
// 通过链表反转，在反转的过程中删除的方式
  let first = null
  let currentNode = null
  while (head) {
    currentNode = head.next
    head.next = first
    first = head
    head = currentNode
  }
  head = first
  first = null
  currentNode = null
  if (n === 1) {
    head = head.next
  }
  while (head) {
    if (--n === 1) {
      currentNode = head.next.next
    } else {
      currentNode = head.next
    }
    head.next = first
    first = head
    head = currentNode
  }
  head = first
  return head
}
```
- 208/208 cases passed (60 ms)
- Your runtime beats 95.55 % of javascript submissions
- Your memory usage beats 83.25 % of javascript submissions (34 MB)
3. 查找链表的长度size，然后用size-n，即是正向需删除节点的位置
```javascript []
var removeNthFromEnd = function(head, n) {
  let size = 0
  let point = head
  while (point) {
    point = point.next
    size++
  }
  n = size - n
  point = head
  if (n == 0) {
    return point.next
  }
  while (point) {
    n--
    if (n === 0) {
      point.next = point.next.next
    }
    point = point.next
  }
  return head
}
```
- 208/208 cases passed (76 ms)
- Your runtime beats 37.96 % of javascript submissions
- Your memory usage beats 81.15 % of javascript submissions (34.1 MB)
4. 双链表思路，就是将n作为两个指针之间的距离，当右节点到达链表最后一个节点时，左边节点所在位置即是应删除的节点
```javascript []
var removeNthFromEnd = function(head, n) {
    //通过双指针方案解决
    let left = head
    let right = head
    while(n--){
        right = right.next
    }
    if(right){
        while(right.next){
            left = left.next
            right = right.next
        }  
        left.next = left.next.next
        return head
    }else{
        left =left.next
        return left
    }
}
```
- 208/208 cases passed (92 ms)
- Your runtime beats 13.36 % of javascript submissions
- Your memory usage beats 82.72 % of javascript submissions (34.1 MB)
