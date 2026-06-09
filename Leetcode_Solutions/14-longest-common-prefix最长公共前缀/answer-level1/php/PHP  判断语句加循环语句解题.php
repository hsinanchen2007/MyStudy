### 解题思路
以当前数组中第一个值为 比较对象  
循环第一个值 取出当前值的第一个字符 来依次对比其他值的第一个字符

### 代码

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
         $str_num = ''; //返回值默认为空
         $count = count($strs);
         if($count == 1){//数量为1 直接返回第一个值
             return  $strs[0];
         }else if($count == 0){
            return $str_num;//空
         }else{
           for($i = 0;$i<strlen($strs[0]);$i++){
               $lnum = $strs[0]{$i};//此处也可以用截取来获取第一个字符
               foreach($strs as $key => $value){
                    if($value{$i} != $lnum){
                        return $str_num;
                    }        
               }
               $str_num .= $lnum;
           }
           return $str_num;
         }
         
    }
}
```