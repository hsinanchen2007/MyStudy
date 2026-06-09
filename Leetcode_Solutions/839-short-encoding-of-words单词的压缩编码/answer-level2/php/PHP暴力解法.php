
- usort — 使用用户自定义的比较函数对数组中的值进行排序
- 按照数组中的字符串的长度倒序排（长度长的在前面，短的在后面）
- 排列好数组之后再去加字符串。
- 反正时间挺慢的，但是一次过。ヽ(￣▽￣)و

---

代码如下：

```php
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function minimumLengthEncoding($words) {
        usort($words,function ($a,$b){
            if (strlen($a) > strlen($b)){
                return -1;
            }else{
                return 1;
            }
        });
        $result = "";
        foreach ($words as $word) {
            if (strrpos($result,$word."#") === false){
                $result .= $word."#";
            }
        }
        return strlen($result);
    }
}
```