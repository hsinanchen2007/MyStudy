### 解题思路
暴力解

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String[]
     */
    function restoreIpAddresses($s) {
        $n = strlen($s);
        $res = [];
        if($n<4) return [];//IP最小长度为4
        //每个数字最多3位数
        for($i=$start;$i<3;$i++){
            for($j=$i+1;$j<$i+4;$j++){
                for($k=$j+1;$k<$j+4;$k++){
                    if($i<$n && $j<$n && $k<$n){
                        $tmp1 = substr($s,0,$i+1);
                        $tmp2 = substr($s,$i+1,$j-$i);
                        $tmp3 = substr($s,$j+1,$k-$j);
                        $tmp4 = substr($s,$k+1);
                        // echo "$tmp1 > $tmp2 > $tmp3 > $tmp4 \n";
                        if($this->valid($tmp1) 
                            && $this->valid($tmp2) 
                            &&$this->valid($tmp3) 
                            &&$this->valid($tmp4)){
                            $res[] = $tmp1.".".$tmp2.".".$tmp3.".".$tmp4;
                        }
                    }
                }
            }
        }
        return $res;
    }
    
    function valid($str){
        if($str==null || strlen($str)==0 || strlen($str)>3 || ($str[0]=='0' && strlen($str)>1) || (int)$str >255){
            return false;
        }
        return true;
    }

}
```