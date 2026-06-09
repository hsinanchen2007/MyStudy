### 解题思路
如果单纯使用递归的话，时间复杂度太高。

使用分治的思想
2^10 = 2^5 * 2^5
2^9 = 2^4 * 2^4 *2

如此，每一次都化简一半。

### 代码

```php
class Solution {

   /**
     * @param Float $x
     * @param Integer $n
     * @return Float
     */
    function myPow($x, $n) {
        $flag=false;
        if($n<1){
            $n*=-1;
            $flag=true;
        }
        $res = $this->helper($x,$n);
        if($flag) {
            return 1/$res;
        }
        return $res;
    }

    function helper($x, $n){
        if($n==1){
            return $x;
        }
        if($n==0){
            return 1;
        }
        $sub_res = $this->helper($x,floor($n/2));
        if($n%2==0){
            return $sub_res*$sub_res;
        }else{
            return $sub_res*$sub_res*$x;
        }
    }
}
```