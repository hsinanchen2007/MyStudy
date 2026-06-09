- 先转化成string型存到数组中，再排序。
- 再遍历转化成int型
- 返回数组即可


```php []
    function lexicalOrder($n) {
        $data = [];
        for ($i = 1; $i <= $n; $i++){
            $data[] = '.'.$i.'.';
        }
        sort($data);

        foreach ($data as $k => $val) {
            $data[$k] = (int)trim($val,'.');
        }
        return $data;
    }
```

