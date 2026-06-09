```
function largestNumber($nums) {
    $str = '';
    $nums = implode('',$nums);
    for($i=0;$i<strlen($nums);$i++)
    {
        $str .= $nums[$i].',';
    }
    $nums = explode(',',$str);
    rsort($nums);
    $nums = implode('',$nums);
    return $nums;
}
```

通过PHP内置函数完成，中间for循环是因为，explode的delimiter不能以''作为条件。