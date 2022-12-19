### 解题思路
1. 遍历单词字符（从右向左）
2. $ans 非空情况下遇到' '则退出遍历，否则对于当前元素非' '情况，$ans++
3. 时间复杂度：O(n) n为字符串长度

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLastWord($s) {
        $length = strlen($s);
        $ans = 0;
        for($i = $length - 1; $i >= 0; $i--){
            if($ans != 0 && $s[$i] == ' '){
                break;
            }
            if($s[$i] != ' '){
                $ans ++;
            }
        }
        return $ans;
    }
}
```