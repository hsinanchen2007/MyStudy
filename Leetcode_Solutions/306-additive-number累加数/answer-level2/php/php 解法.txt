![微信截图_20191107151748.png](https://pic.leetcode-cn.com/053fd3b633357ad31eee0ccc19be730c311b61e7185eac2e47eda38768c705c9-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191107151748.png)

解析思路都在注释里了
```
class Solution {

    /**
     * @param String $num
     * @return Boolean
     */
    function isAdditiveNumber($num) {
        $len = strlen($num);
        if($len<3) return false;
        for($i=1;$i<=floor($len/2);$i++){// 第一个数的长度不可能超过一半
            $string1 = substr($num,0,$i); // [0,$i)组成$int1
            $int1 = (int) $string1;
            if($string1 !== (string) $int1) continue;// 累加序列里的数不会以 0 开头
            for($j=$i+1;$j<=floor($i+($len-$i)/2);$j++){// 第二个数的长度不可能超过第一个数剩下的一半
                $string2 = substr($num,$i,$j-$i); // [$i,$j)组成$int2
                $int2 = (int) $string2;
                if($string2 !== (string) $int2) continue;
                if($this->helper(substr($num,$j), $int1, $int2)) return true;
            }
        }
        return false;
    }
    // 该函数用于判断$int1、$int2是否与$str组成累加序列
    function helper($str, $int1, $int2){
        if($str === "" || $str === false) return true;
        $sum = $int1 + $int2;
        $sums = (string) $sum;
        if(strpos($str, $sums)!==0) return false;
        return $this->helper(substr($str,strlen($sums)), $int2, $sum);
    }
}
```
