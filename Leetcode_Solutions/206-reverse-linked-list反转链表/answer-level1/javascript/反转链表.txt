
### 解法一：暴力法
先从最常规思路起手。
对每个节点进行遍历处理，用一个数组按顺序保存每个节点。
再将数组从后向前遍历，并同时修改当前节点的指针为前一个节点。

```javascript
var reverseList = function(head) {
    if(!head) return head;
    var arr = [head];
    var cur = head;
    while(cur) {
        arr.push(cur);
        cur = cur.next;
    }
    for(let i = arr.length - 1; i >= 0; i --) {
        arr[i].next = arr[i-1];
    }
    arr[0].next = null;
    return arr[arr.length-1];
}
```

### 解法二：迭代法
其实我们根本没有必要用到这个数组。
我们可以只用一个变量保存前一个节点，在遍历节点的时候，直接修改当前节点的指针为前一个节点。

```javascript
var reverseList = function(head) {
    if(!head) return head;
    var cur = head;
    var pre = null;
    while(cur) {
        let temp = cur.next;
        cur.next = pre; 
        pre = cur; 
        cur = temp; 
    }
    return pre;
};
```

### 解法三：递归法
递归法大体也与迭代法相同，只是最后结束前要提前返回当前操作的节点。

```javascript
var reverseList = function(head, pre=null) {
    if(!head) return head; 
    let temp = head.next; 
    head.next = pre; 
    pre = head; 
    head = temp; 
    if(!head) return pre
    return reverseList(head, pre); 
}
```













```