
```php
function middleNode($head)
{
    // 快慢指针
    $slow = $fast = $head;
    while ($fast && $fast->next) {
        $slow = $slow->next;
        $fast = $fast->next->next;
    }

    return $slow;
}
```
