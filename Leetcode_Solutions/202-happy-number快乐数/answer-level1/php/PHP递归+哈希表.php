- 建立哈希表,记录相加总合
- 递归计算相加结果
```
class Solution {
    public $hash = [];
    /**
     * @param Integer $n
     * @return Boolean
     */
    function isHappy($n) {
        if ($n == 1) return true; 
        $count = strlen($n);
        $num = 0;
        $n = (string)$n;
        for ($i=0;$i<$count;$i++) {
            $num += $n[$i] * $n[$i];
        }
        if (isset($this->hash[$num])) {
            return false;
        } else {
            $this->hash[$num] = 1;
        }
        if ($num == 1) {
            return true;
        } else {
            return $this->isHappy($num);
        }
    }
}
```
