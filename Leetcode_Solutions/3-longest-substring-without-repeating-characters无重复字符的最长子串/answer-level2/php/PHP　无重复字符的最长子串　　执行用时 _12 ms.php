```
//    执行用时 :12 ms, 在所有 PHP 提交中击败了97.99%的用户
//    内存消耗 :14.5 MB, 在所有 PHP 提交中击败了97.82%的用户

 /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
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
              //每一次过去后，比较当前的tmp 与上一次的 len 谁更大
              $len = strlen($tmp)>$len ? strlen($tmp) : $len;
          }
          return $len;//最后返回的长度 不一定是$tmp
    }


/*
[substr]    https://www.php.net/manual/zh/function.substr.php
    substr ( string $string , int $start [, int $length ] ) : string
    返回字符串 string 由 start 和 length 参数指定的子字符串。 如果 string 的长度小于 start，将返回 FALSE。

    $start>0 返回的字符串将从 string 的 start 位置开始
            例如：echo substr('abcdef', 1, 3);  // bcd 也就是[$start,$start+$length]范围的字符
    $start<0 返回的字符串将从 string 结尾处向前数第 start 个字符开始。
            例如：echo substr("abcdef", -3, 1); // d   字符串最后一个字符为-1


[strpos]    https://www.php.net/manual/zh/function.strpos.php
     strpos ( string $haystack , mixed $needle [, int $offset = 0 ] ) : int
     strpos — 返回 needle 在 haystack 中首次出现的数字位置。
     如果是第一个值就找到，那么返回是0 (注意字符串位置是从0开始，而不是从1开始的。)
     如果没找到 needle，将返回 FALSE。

     所以如果想要判断 不存在，一定要用全值比对 ===
*/
```
