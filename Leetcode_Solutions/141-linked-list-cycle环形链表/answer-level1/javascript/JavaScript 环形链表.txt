解一：

> 由上到下给每一层遍历到的结点做上标记，如果在下一个结点中出现了这个标记，则表示存在环形结构。如果不想篡改原始数据，可以先用`temp`保存。

```js
var hasCycle = function(head) {
    while(head){
        if (head.val==='rhinoc.top') return true;
        else head.val='rhinoc.top';
        head = head.next;
    }
    return false
};
```

解二：

> 利用`JSON.stringify()`不能字符串化含有循环引用的结构。

```js
var hasCycle = function(head) {
    try{
        JSON.stringify(head);
        return false;
    }
    catch(err){
        return true;
    }
};
```

解三：

> （双指针法）设置一快一慢两个指针，快指针一次走两步到`.next.next`，慢指针一次走一步到`.next`，如果链表不存在环形结构，那么快指针和慢指针不会相遇。如果存在环形结构，快指针总会和慢指针相遇。

```js
var hasCycle = function(head) {
    if(head === null || head.next === null) return false;
    var slow = head;
    var fast = head.next;
    while (slow != fast){
        if (fast === null || fast.next === null) return false;
        slow = slow.next;
        fast = fast.next.next;
    }
    return true;
};
```