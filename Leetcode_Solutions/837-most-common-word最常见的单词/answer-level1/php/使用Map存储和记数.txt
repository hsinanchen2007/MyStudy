### 解题思路
把字符串按照空格分词，遍历每个单词，过滤标点，存入map中，记录出现最大次数的单词。

### 注意：
0、存在如下case, 直接用空格分词不可行
```
"a, a, a, a, b,b,b,c, c"
["a"]
```
1、过滤单词中标点，不仅仅是逗号和点号，还有很多，不能直接用trim。这里用正则。
```
$word = strtolower(trim(trim($word, ','), '.'));
```

### 性能
为啥是双100啊，正则问题应该很大的。

执行用时 :4 ms, 在所有 php 提交中击败了100.00%的用户
内存消耗 :15 MB, 在所有 php 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $paragraph
     * @param String[] $banned
     * @return String
     */
    function mostCommonWord($paragraph, $banned) {
        $map = [];
        $target_word = '';
        $target_num = 0;
        $paragraph = preg_replace('/[[:punct:]\s]/', ' ', $paragraph);
        
        $words = explode(' ', $paragraph);
        foreach ($words as $word) {
            $word = strtolower(preg_replace('/[[:punct:]\s]/','',$word));
            if (in_array($word, $banned) OR $word == '') {
                continue;
            }

            $map[$word] += 1;
            if ($map[$word] > $target_num) {
                $target_num = $map[$word];
                $target_word = $word;
            }
        }

        return $target_word;
    }
}
```

### 参考
[https://leetcode-cn.com/problems/most-common-word/solution/zui-chang-jian-de-dan-ci-by-leetcode/](https://leetcode-cn.com/problems/most-common-word/solution/zui-chang-jian-de-dan-ci-by-leetcode/)