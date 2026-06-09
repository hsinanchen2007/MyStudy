### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     * linxiu
     */
    function compressString($S) {
            $len=strlen($S);//得到字符串长度
            $arr=str_split($S);//拆分为数组
            $num=1;          //定义一个统计数
            for($i=0;$i<$len;$i++){//遍历数组
              if($arr[$i]==$arr[$i+1]){
                $num++;
              }else{
                  $str.=$arr[$i].$num;
                  $num=1;//重置统计数
              }
            }
            if(strlen($str)>=$len){//判断最终压缩的字符串长度和原来字符串长度
                return $S;
            }else{
                return $str;
            }
    }
}
```