三种思路：
    1. 利用整数的取模运算,只反转整数的一半（如何判断是一半）
        我们将原始数字除以 10，然后给反转后的数字乘上 10，所以，当原始数字小于反转后的数字时，就意味着我们已经处理了一半位数的数字。
    2. 利用字符串反转函数，将整数当作字符串看待
    3. 不使用现成的字符串，利用两个指针$l $r来循环判断

```
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
     //执行用时 :32 ms, 在所有 PHP 提交中击败了82.01%的用户
     //内存消耗 :14.8 MB, 在所有 PHP 提交中击败了23.14%的用户
    function isPalindrome($x) {
          // if($x == (int)strrev($x)){//改这里为减法
          if($x < 0 || $x - strrev($x) != 0)//负数肯定不是回文数
                    return false;
          else
                    return true;

    }

    //执行用时 :44 ms, 在所有 PHP 提交中击败了44.59%的用户
    //内存消耗 :14.8 MB, 在所有 PHP 提交中击败了15.69%的用户
    function isPalindrome2($x) {
           //如果整数末尾是0 那么回文数除了0，没有其他值。
           //负数一定不是回文数 例如 -11=> 11-
          if( $x<0 || ($x % 10 == 0 && $x != 0) ){
              return false;
          }

          $rex = 0;//反转的数
          while( $x > $rex) {
              $rex = $rex*10 + $x%10;//反转
              $x   = ($x-$x%10)/10;//由于PHP弱语言，这里要处理成整数
          }
          //1221反转一半x是12，rex 是12，
          //12321反转到x<rex 时候，x是12，rex 是123
          if($x == $rex || $x ==($rex-$rex%10)/10){
              return true;
          }else{
              return false;
          }
    }

    //利用双指针
    //执行用时 :24 ms, 在所有 PHP 提交中击败了94.11%的用户
    //内存消耗 :14.8 MB, 在所有 PHP 提交中击败了9.80%的用户
    function isPalindrome3($x) {
        if($x<0) return false;
        if($x<10) return  true;//顺序不能颠倒
        $str = (string)$x;
        $l   = 0;
        $r   = strlen($str)-1;
        while($l < $r) {
            if($str[$l] != $str[$r]){//例如1224 那么首先比较了 1与4 不相等直接返回
                return false;//这里利用两个指针相当于加快了判断不是回文数
            }
            $l++;
            $r--;
        }
        return true;//但是如果判断出来时回文数，那么必定已经遍历过一遍了
    }
}

```
