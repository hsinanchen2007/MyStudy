### 解题思路
此处撰写解题思路
我的思路也即是最直观的解题方式，
1. 首先统计chars中各个字符串的个数；
2. 遍历words，每个word遍历字符串，统计各个字符串的字数，若比chars中字符串的少，则符合条件
3. 一次遍历即可
### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $charLen = strlen($chars);
        for ($i = 0; $i < $charLen; $i ++) {
            $arrChars[$chars[$i]] ++;
        }
        $len = 0;
        foreach ($words as $word) {
            $arr = [];
            $wordLen = strlen($word);
            for ($i = 0; $i < $wordLen; $i ++) {
                $arr[$word[$i]] ++;
                if ($arr[$word[$i]] > $arrChars[$word[$i]]) {
                    continue 2;
                }
            }
            $len += $wordLen;
        }

        return $len;
    }
}
```