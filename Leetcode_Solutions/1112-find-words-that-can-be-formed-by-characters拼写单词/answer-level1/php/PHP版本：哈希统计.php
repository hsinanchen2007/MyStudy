### 解题思路
1.构建数组hashChars：字符串中每个字符的个数
2.循环数组words: 通过判断每个word中的字母是否在hashChars中
3.返回count

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
        $hashChars = [];

        for($i = 0; $i < $charLen; $i++) {
            $hashChars[$chars[$i]] = ($hashChars[$chars[$i]] ?? 0) + 1;
        }

        $wCount = count($words);
        $count = 0;
        
        for ($i = 0; $i < $wCount; $i++) {
            $wLen = strlen($words[$i]);
            $flag = 1;
            $tempHash = $hashChars;
            
            for($j = 0; $j < $wLen; $j++) {
                if (isset($tempHash[$words[$i][$j]]) && $tempHash[$words[$i][$j]] > 0) {
                    $tempHash[$words[$i][$j]]--;
                } else {
                    $flag = 0;
                    break;
                }
            }

            if ($flag == 1) {
                $count += $wLen;
            }
        }
        return $count;

    }
}
```