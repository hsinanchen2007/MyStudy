### 解题思路
找规律，边界值
分析题目我们能发现
1.在首行向下到尾行阶段，横坐标增加1，纵坐标不变
2.在尾行向上到首行阶段，横坐标减少1，纵坐标增加1
...保持这个规律，循环往复，就能得到Z形数组
继而循环得到最终结果^_^

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        if (!$s) return '';
        $sl = str_split($s);
        $map = [];
        $i = $j = 0;
        $iPlus = 1;
        $jPlus = 0;
        foreach ($sl as $k=>$v) {
            $map[$i][$j] = $v;
            $kPlus = $k + 1;
            if (($i + 1) == $numRows) {
                $iPlus = -1;
                $jPlus = 1;
            } elseif ($i==0) {
                $iPlus = 1;
                $jPlus = 0;
            }
            $i += $iPlus;
            $j += $jPlus;
        }
        $result = '';
        foreach ($map as $k=>$v) {
            foreach ($v as $kk=>$vv) {
                $result .= $vv;
            }
        }
        return $result;
    }
}
```