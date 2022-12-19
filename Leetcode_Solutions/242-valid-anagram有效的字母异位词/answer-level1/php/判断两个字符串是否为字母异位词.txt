### 解题思路

1. 首先需要判断两个字符串的长度是否一致，否则一定不是。
2. 一共26个英文字母元素，可以初始化个数据用字母做下标，用来存储对应字母在字符串中出现的次数
3. 先通过将一个词中匹配到的对应字母的个数进行自增
4. 再通过将另一个词中匹配到的对应字母的个数进行自减
5. 最终对应字母的个数为零则说明是字母异位词

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isAnagram($s, $t) {
        $sLength = strlen($s);
        $tLength = strlen($t);
        if($sLength != $tLength){
            return false;
        }

        $pool = ["a"=>0,"b"=>0,"c"=>0,
        "d"=>0,"e"=>0,"f"=>0,
        "h"=>0,"i"=>0,"j"=>0,
        "k"=>0,"l"=>0,"m"=>0,
        "n"=>0,"o"=>0,"p"=>0,
        "q"=>0,"r"=>0,"s"=>0,
        "t"=>0,"u"=>0,"v"=>0,
        "w"=>0,"x"=>0,"y"=>0,
        "z"=>0];
        
        for($i=0;$i<$sLength;$i++){
            $pool[$s[$i]] += 1; 
            $pool[$t[$i]] -= 1;
        }

        foreach($pool as $v){
            if($v != 0){
                return false;
            }
        }

        return true;
    }
}
```