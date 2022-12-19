### 解题思路
通过3个指针来实现。

第3步不太好理解，理解清楚了写起来很容易。

算法：
1. 定义3个指针，读指针read遍历字符数组，写指针write指向压缩后的字符数组，锚指针anctor指向相同序列的起始位置。3个指针开始都指向字符第一个元素。
2. 移动指针read遍历字符数组, 如果同一个字符序列没有读完，继续读，直到读完（读到字符结尾或下一个字符不同当前字符）。
3. 相同序列字符读完后，开始写入，此时指针read指向此序列尾部。指针anctor指向为当前序列字符，当前序列长度为$read - $anctor + 1。先写入当前字符$chars[$anctor], 在写入长度【相同序列只有一个字符的时候，长度为1不需要记录，所以需要判断$read > $anctor的时候才写入长度；另外长度可能是多位数，比如100，需要写入3个字符，'1', '0', '0', 故而需要把数字转为字符串遍历写入】，同时写指针不断移动。
4. 当前序列写完后，锚指针anctor指向下一个序列的开始位置即$read + 1。
5. 返回写指针$write, write即为压缩后字符的长度。

### 性能
执行用时 :16 ms, 在所有 php 提交中击败了66.67%的用户
内存消耗 :15.4 MB, 在所有 php 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $chars
     * @return Integer
     */
    function compress(&$chars) {
        $read = $write = $anctor = 0;
        $len = count($chars);
        for ($read = 0; $read < $len; $read++) {
            if ($chars[$read + 1] == $len OR $chars[$read] != $chars[$read + 1]) {
                $chars[$write++] = $chars[$anctor];
                if ($read > $anctor) {
                    $str_count = (string)($read - $anctor + 1);
                    for ($i = 0; $i < strlen($str_count); $i++) {
                        $chars[$write++] = $str_count[$i];
                    }
                }
                $anctor = $read + 1;
            }
        }

        return $write;
    }
}
```

### 参考
[https://leetcode-cn.com/problems/string-compression/solution/ya-suo-zi-fu-chuan-by-leetcode/](https://leetcode-cn.com/problems/string-compression/solution/ya-suo-zi-fu-chuan-by-leetcode/)