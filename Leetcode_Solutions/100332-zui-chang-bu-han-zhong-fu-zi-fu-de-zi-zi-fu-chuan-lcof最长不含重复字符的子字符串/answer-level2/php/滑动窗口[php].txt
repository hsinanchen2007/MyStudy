### 解题思路
见代码

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $head=0;
        $tail=0;
        $res=1;
        $length=strlen($s);

        //边界条件
        if($length<2) return $length;

        while($tail<$length-1){
            $tail++;

            //tail指向的新的字母没有在子串里，则窗口扩充+1
            if(strpos(substr($s,$head,$tail-$head),$s[$tail])===false){
                $res = max($tail-$head+1,$res);
            }else{
                //如果tail指向的字母在子串里，则head一直右移，直到窗口里没有重复的数字
                while(strpos(substr($s,$head,$tail-$head),$s[$tail])!==false){
                    $head++;
                }
            }
        }
        return $res;
    }
}
```