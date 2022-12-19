### 解题思路
1. 每个字符串进行排序（PHP 中先打散为数组，排序后再组装），排序后的字符串作为 key，排序前的字符串作为值，添加到返回值中即可
2. 借助 26 个字母与素数的一个映射集。求积可得唯一 key，相当于一个无冲突的 hash function

### 代码 1

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String[][]
     */
    function groupAnagrams($strs) {
        $map = [];
        foreach ($strs as $str) {
            $arr = str_split($str);
            sort($arr);
            $tmp_str = implode("", $arr);
            $map[$tmp_str][] = $str;
        }
        return array_values($map);
    }
}
```

### 代码 2

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String[][]
     */
    function groupAnagrams($strs) {
        $resArr = [];
        // 将 26 个字母映射为 素数，求积可得唯一 key，相当于一个无冲突的 hash function
        $prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103];
        foreach ($strs as $str) {
            $strlen = 1;
            for ($i = 0; $i < strlen($str); $i++) {
                $strlen *= $prime[ord($str[$i]) - 97];
            }
            $resArr[$strlen][] = $str;
        }
        return array_values($resArr);
    }
}
```