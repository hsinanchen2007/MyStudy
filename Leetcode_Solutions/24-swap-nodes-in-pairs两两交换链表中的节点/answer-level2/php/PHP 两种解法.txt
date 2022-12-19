## 非递归解法

借助一个虚拟头节点，画图

```php
function swapPairs($head)
{
    if ($head === null || $head->next === null) {
        return $head;
    }

    $dummyHead = new ListNode(null);
    $dummyHead->next = $head;
    $cur = $dummyHead;
    while ($cur->next !== null && $cur->next->next !== null) {
        $a = $cur->next;
        $b = $cur->next->next;
        $cur->next = $b;
        $a->next = $b->next;
        $b->next = $a;
        $cur = $cur->next->next;
    }

    return $dummyHead->next;
}
```

## 递归解法

```php
function swapPairs($head)
{
    // 递归函数的含义，返回后续所有节点两两交换之后的头节点
    // terminator
    if ($head === null || $head->next === null) {
        return $head;
    }

    $next = $head->next;
    $head->next = $this->swapPairs($next->next);
    $next->next = $head;
    return $next;
}
```
