### 解题思路
感谢[@tacks](/u/tacks/)的思路，又加了一个更优化的解

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        /*-- 解#1 --
        if(strlen($s)>1){
            $max = 0;//最长串长度
            $lib = array();//储存不同字母
            for($i=0;$i<strlen($s);$i++){
                if(in_array($s[$i],$lib)){//if found duplicate
                    array_splice($lib,0,array_search($s[$i],$lib)+1);//remove the leading elements
                    array_push($lib,$s[$i]);//starting from the current element
                }
                else{
                    array_push($lib,$s[$i]);//push new element to array
                    if(sizeof($lib) > $max){
                        $max = sizeof($lib);//replace max length if higher val is found
                    }
                    // print_r($lib);
                }
            }

            if($max == 0) $max = strlen($s);//return the string length if string is too small
        }
        else{
            $max = strlen($s);//return the string length if string is even smaller
        }

        return $max;
        */



        //解#2
        $lens = strlen($s);//总的字符串有多长
        $tmp  = '';       //用于存储子串  当前里面不会有重复的字符
        $len  = 0;        //最长子串的长度
        for($i=0; $i<$lens; $i++) {
            $re = strpos($tmp,$s[$i]);//判断 是否有重复的
            if(false !== $re) {//有重复
                $tmp .= $s[$i];//先追加上去 例如pww
                $tmp  = substr($tmp,$re+1);//从重复位置开始 截取后 pww=>w
            }else {//无重复字符
                $tmp .= $s[$i];//追加到后面
            }

            if(strlen($tmp) > $len){
                $len = strlen($tmp);
            }
        }
        return $len;//最后返回的长度 不一定是$tmp
        
        
    }
}
```