**思路**  
&emsp;&emsp;实现一个函数clear, 接受的参数是头结点, 我们的目标是, 每次只处理开头的结点, 后面的结点递归处理。此时可能有下面这几种情况:
1. 开头的元素没有重复, 那我们直接处理head后面的链表, 并且让head.next = clear(head.next), 递归处理后面的链表  
2. 开头元素有重复, 找到第一个不同的结点, 调用clear函数, 然后返回函数返回的结果  
3. 递归结束的条件是head为空或者head的next为空  
这样最后返回的结果就是我们想要的结果了  
```javascript []
var deleteDuplicates = function(head) {
    function clear(head) {  
        //递归中止条件
        if(!head || !head.next) return head;
        //如果并没有重复结点, 直接让head的next等于下一个处理结果
        if(head.next.val != head.val) {
            head.next = clear(head.next);
            
            return head;
        }
        //有重复元素, 需要找到第一个不同的结点, 这里是head.next. 
        while(head.next && head.next.val === head.val) {
            head = head.next;
        }
          
        return clear(head.next);
    }
    
    return clear(head);
};
```
