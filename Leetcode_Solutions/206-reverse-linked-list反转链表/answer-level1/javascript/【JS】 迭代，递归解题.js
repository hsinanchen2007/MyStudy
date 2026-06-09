### 解题思路
1.迭代

时间复杂度：O(n)
空间复杂度：O(1)

### 代码

```javascript

var reverseList = function(head) {
    let [prev, curr] = [null, head];    //解构赋值，建立两个迭代指针
    while (curr) {                      //不为空就继续执行
        let temp = curr.next;           //把next存储在临时变量
        curr.next = prev;               //指向前一项
        prev = curr;                    //prev向前进一位
        curr = temp;                    //curr向前进一位
    }
    return prev;
};
```

### 解题思路
2.递归

时间复杂度：O(n)
空间复杂度：O(n)

### 代码

```javascript

var reverseList = function(head) {
   if(head==null || head.next==null){
        return head;
    };
    let reversed = reverseList(head.next);
    let NEXT = head.next;
    head.next = null;
    NEXT.next = head;
    return reversed;
};
```