### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $str1
     * @param String $str2
     * @return String
     * linxiu
     */
    function gcdOfStrings($str1, $str2) {
         if($str1.$str2!=$str2.$str1){//两个字符串分别拼接如果不一样返回空；
        return '';
    }
    if(!$str1||!$str2){//两个字符串是空串返回空；
        return '';
    }
    $len1=strlen($str1);//获取字符串长度
    $len2=strlen($str2);
    $y=1;
    while($y!=0){//当第一个字符串长度和第二个字符串长度的余数为0时得到公因子的长度
            $y=$len1%$len2;
            $len1=$len2;
            $len2=$y;
        }
       $len=$len1;
    $str=substr($str1,0,$len);//截取从开始到公因子长度；
    return $str;
}
}
```