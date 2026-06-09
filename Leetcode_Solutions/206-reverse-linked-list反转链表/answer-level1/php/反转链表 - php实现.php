#### 1. 迭代法

```php
    function reverseList($head) {
        $current_node = $head;
        $prev_node = null;
        while ($current_node !== null) {
            $next_node = $current_node->next;
            $current_node->next = $prev_node;
            $prev_node = $current_node;
            $current_node = $next_node;
        }
        return $prev_node;
    }
```

#### 2. 递归法

```php
    function reverseList($head) {
        if ($head === null || $head->next === null) {
            return $head;
        }

        $res = $this->reverseList($head->next);

        $head->next->next = $head;
        $head->next = null;
        return $res;
    }
```