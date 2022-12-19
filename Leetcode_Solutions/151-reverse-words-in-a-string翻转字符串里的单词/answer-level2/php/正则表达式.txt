这道题大佬们确实太顶了，一行代码完事，思路没啥说的，就是去掉多余的空格只保留有效单词在数组，最后
再用空格拼起来,正则表达式太强了，中间就算再来俩逗号都无所谓
```
function reverseWords($s) {
        $arr=preg_split("/[\s]+/",trim($s));
        //这里直接翻转字符再拼接都可以 
        //例如：return implode(' ',array_reverse($arr));
        $str="";
        for($i=count($arr)-1;$i>=0;$i--)
        {
            $str.=$arr[$i];
            if($i!=0)
                $str.=' ';
        }
        return $str;
    }
```
