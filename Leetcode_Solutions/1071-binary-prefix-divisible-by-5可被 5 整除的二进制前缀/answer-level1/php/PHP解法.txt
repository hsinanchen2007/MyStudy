### 关键点
- 左移计算十进制结果
- 取余后加上下一个值结果

### 误区&注意点
- 十进制计算结果超大时PHP取余会溢出,出现负数
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Boolean[]
     */
    function prefixesDivBy5($A) {
        $count = count($A);
        $out = [];
        $res = 0;
        for ($i=0;$i<$count;$i++) {
            $res = ( $res << 1 ) % 5 + ($A[$i]);
            $out[] = $res % 5 == 0 ? true : false;
        }
        return $out;
    }
}
```
