```
function singleNumber($nums)
{
    $count = array_count_values($nums);     //算出重复的值
    $result = array_keys($count, 1);        //获取数据为1的键，表示值出现一次
    return $result;
}
```