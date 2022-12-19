```

function fibonacci($n = 0)
{
    if($n < 2) {
        return $n;
    } else {
        $arr[0] = 0;
        $arr[1] = 1;
        $tmp = 0;
        for ($i = 0; $i < $n; $i++) {
            $tmp = $arr[0] + $arr[1];
            $arr[0] = $arr[1];
            $arr[1] = $tmp;
        }

        return $tmp;
    }
}
```
