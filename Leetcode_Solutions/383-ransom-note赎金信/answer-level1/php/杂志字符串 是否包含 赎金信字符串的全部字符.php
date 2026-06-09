### 解题思路
遍历赎金信字符串
若不被杂志包含 返回false;若包含，则替换杂志字符串被包含的字符为# 
循环执行
遍历完毕 说明全部被包含返回true

### 代码

```php
class Solution {

    /**
     * @param String $ransomNote
     * @param String $magazine
     * @return Boolean
     */
    function canConstruct($ransomNote, $magazine) {
        for($i=0;$i<strlen($ransomNote);$i++) {
            $pos = strpos($magazine, $ransomNote[$i]);
            if(false !== $pos) { 
                $magazine[$pos] = '#';
            }else{
                return false;
            }
        }
        return true;
    }
}
```