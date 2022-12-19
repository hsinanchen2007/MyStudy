### 解题思路
此处撰写解题思路
这个就是看了网上的滑动窗口改的，可能用了数组造成内存有点大，不知道那些大神是怎么把内存降低的，时间降低的
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $strarr=array();$length=strlen($s);
        //先把字符切割下便于使用数组
        for($i=0;$i<$length;$i++){
            $strarr[$i]=substr($s,$i,1);
        }
        $setarr=array();//临时字符串数组
        $i=0;//临时字符串左边起始位置
        $j=0;//临时字符串右边起始位置
        $max=0;//
        while($i<$length&&$j<$length){
            $k=$strarr[$j];
            if(array_search($k,$setarr)===false){
                //不包含就右移变长
                $setarr[]=$k;
                $j++;
                $max=$max<$j-$i?$j-$i:$max;
            }else{
                //包含就左移缩短去掉重复
                unset($setarr[$i]);
                $i++;
            }
        }
        return $max;
    }
}
```