### 解题思路
过滤牌照中的非字母，后都转为小写。遍历每一个词，检查词中的每个字符是否在牌照中，在就从牌照中去掉，最后牌照为空说明是完整词。

### 性能
执行用时 :32 ms, 在所有 PHP 提交中击败了33.33%的用户
内存消耗 :14.7 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $licensePlate
     * @param String[] $words
     * @return String
     */
    function shortestCompletingWord($licensePlate, $words) {
        $str = strtolower(str_replace(' ', '', $licensePlate));
        $license = [];
        for ($i = 0; $i < strlen($str); $i++) {
            if (!in_array($str[$i], ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10'])) $license[] = $str[$i];
        }

        // 注意每个词的长度【1, 15】, 这里用16表示最大长度。
        $target = str_repeat('0', 16);
        foreach ($words as $word) {
            $tmp = $license;
            for ($i = 0; $i < strlen($word); $i++) {
                if (($key = array_search($word[$i], $tmp)) !== false) {
                    unset($tmp[$key]);
                }

                if (empty($tmp)) {
                    $target = strlen($word) < strlen($target) ? $word : $target;
                    break;
                }
            }
        }

        return $target;
    }
}
```

### 算法复杂度
- 时间复杂度： O(N)
- 空间复杂度： O(N)

### 参考
[https://leetcode-cn.com/problems/shortest-completing-word/comments/69839](https://leetcode-cn.com/problems/shortest-completing-word/comments/69839)