- 建立计数哈希表
- 设计公约数函数
- 递归实现统计比较
```
class Solution {

    /**
     * @param Integer[] $deck
     * @return Boolean
     */
    function hasGroupsSizeX($deck) {
        if (empty($deck) || count($deck) == 1) {
            return false;
        }
        $count = count($deck);
        $hash = [];
        for ($i=0;$i<$count;$i++) {
            if (isset($hash[$deck[$i]])) {
                $hash[$deck[$i]] += 1;
            } else {
                $hash[$deck[$i]] = 1;
            }
        }
        
        sort($hash);
        if (count($hash) == 1) {
            if ($hash[0] >= 2) {
                return true;
            } else {
                return false;
            }
        }
        
        $res = $this->gcd($hash[0],$hash[1]);
        for ($i=2;$i<count($hash);$i++) {
            $res = $this->gcd($res, $hash[$i]);
            if ($res==1) {
                return false;
            }
        }
        return true;
    }
    # 公约数函数,求解最小公约数
    function gcd($a,$b) {
        if ($a>=$b) {
            return $a%$b ? $this->gcd($b,$a%$b) : $b;
        } else {
            return $b%$a ? $this->gcd($a, $b%$a) : $a;
        }
    }
}
```
