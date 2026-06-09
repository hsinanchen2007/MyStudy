```javascript
var deleteDuplicates = function(head) {
    let fake = new ListNode();
    fake.next = head; // 插入了一个虚拟的头结点以便操作
    if(!fake.next) return fake.next; // 检查链表是否为空
    let p = fake, f = p.next, b = f.next, flag = false;
    while(f && b) { 
        if(f.val != b.val) { // 若前向指针f和后向指针b的值不同
            if(!flag) { // 若之前未发生相同数值的情况
                p = f; // 重置p指针
            } else {
                p.next = b; // 否则把p到b中的所有元素删除
            }
            flag = false; // 清空标志
        } else {
            flag = true; // 发生了值相同的情况
        }
        f = b;
        b = b.next; // 前后指针向后移动一格
    };
    if(flag) p.next = b; // 收尾处理一下
    return fake.next;
};
```