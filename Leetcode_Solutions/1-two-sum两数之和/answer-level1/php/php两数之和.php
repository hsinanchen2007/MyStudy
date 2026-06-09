```php []
function handle($arr, $target)
{
    foreach ($arr as $k => $v) {
        if (is_int($v)) { // 必须是整形
            $num = $target - $v;
            if (in_array($num, $arr)) { // 此时表示已经找到相加值等于指定值了
                if ($num != $v) { // 不能是自己
                    echo '我是' . $num . '，我的下标是：' . array_search($num, $arr);
                    echo '<br />';
                    echo '我是' . $v . '，我的下标是：' . $k;
                    break;
                }
            }
        }
    }
}
```
