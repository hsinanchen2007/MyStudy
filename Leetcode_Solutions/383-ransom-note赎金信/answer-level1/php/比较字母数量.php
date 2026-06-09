### 解题思路
算法：
0、遍历，存储$magazine中每个字母的数量在$res数组中
1、遍历$ransomNote，把每个字母在$res中-1，如果结果小于0，就说明$magazine中字母数量多，返回false。

注意$ransomNote中字母在$res中不存在的情况，需要初始化为0，否则是NULL，无法运算

### 性能
执行用时 :12 ms, 在所有 php 提交中击败了93.33%的用户
内存消耗 :15.3 MB, 在所有 php 提交中击败了33.33%的用户

### 代码

```php
class Solution {

    /**
     * @param String $ransomNote
     * @param String $magazine
     * @return Boolean
     */
    function canConstruct($ransomNote, $magazine) {
        $res = [];
        for ($i = 0; $i < strlen($magazine); $i++) {
            $res[$magazine[$i]]++;
        }

        for ($i = 0; $i < strlen($ransomNote); $i++) {
            if (!isset($res[$ransomNote[$i]])) {
                $res[$ransomNote[$i]] = 0;
            }
            if (--$res[$ransomNote[$i]] < 0) {
                return false;
            }
        }

        return true;
    }
}
```

### 参考
[数组存储字母数量](https://leetcode-cn.com/problems/ransom-note/solution/shu-zu-cun-chu-zi-mu-shu-liang-by-imaginee/)