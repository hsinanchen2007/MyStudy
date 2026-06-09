![微信截图_20190829200040.png](https://pic.leetcode-cn.com/9607ea00b9f981681153bbbd5aa259b257032ded19ac882ccc8f3521dc55b647-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190829200040.png)

```
class Solution {

    /**
     * @param Integer $n
     * @param Integer $k
     * @return String
     */
    function getPermutation($n, $k) {
        $ans = '';
        $left_arr = [];
        for($i=0;$i<$n;$i++){
            $left_arr[$i] = $i+1;
        }
        $this->backtarck($ans,$left_arr,$n,$k);
		return $ans;
    }
    
    function backtarck(&$ans,$left_arr,$n,$k){
        if($n == 1){
            $ans = empty($left_arr)?$ans:$ans.implode("",$left_arr);
            return;
        }
        $index = ceil($k/$this->factorial($n-1));
		$mod = fmod($k,$this->factorial($n-1));
        $k = $mod==0?$this->factorial($n-1):$mod;
        $ans .= $left_arr[$index-1];
        array_splice($left_arr,$index-1,1);
        $this->backtarck($ans,$left_arr,$n-1,$k);
    }
    
    // 阶乘
    function factorial($n){
        if($n==0) return 1;
        if($n<=1) return $n;
        return $n*$this->factorial($n-1);
    }
}
```
