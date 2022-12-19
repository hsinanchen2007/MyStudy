### 解题思路
[参考这位老哥的](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/liang-tang-bian-li-by-z1m/)

### 代码

```php
class Solution {

    /**
     * @param Integer[] $a
     * @return Integer[]
     */
    function constructArr($a) {
        $n=count($a);
        $l=array_fill(0,$n,1);
        $r=array_fill(0,$n,1);

        for($i=1;$i<count($l);$i++){
            $l[$i] = $l[$i-1] * $a[$i-1];
        }

        for($j=count($r)-2;$j>=0;$j--){
            $r[$j] = $r[$j+1] * $a[$j+1];
        }

        for($i=0;$i<count($l);$i++){
            $l[$i] = $l[$i] * $r[$i];
        }
        return $l;
    }
}
```