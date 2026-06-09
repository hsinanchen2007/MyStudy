取余合并
```php
function rotate(&$nums, $k) {
        $k = $k%count($nums);//取余防止k>nums的长度
        $nums = array_merge(array_splice($nums, -1*$k, $k),$nums);
}
```

