### 上一篇代码中有错误，抱歉！修改如下：
```
if (!head || !head.next) return false
  // 快慢指针
  let slow = head
  let quick = head
  while(quick) {
    if (!quick.next) return false
    quick = quick.next.next
    slow = slow.next
    if (quick === slow) return true
  }
  return false
```
