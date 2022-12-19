### 解题思路
方法太笨重后期优化
循环比较
循环长度利用max(最长字符串的循环)
不满住条件的截取

### 代码
```php
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $count = count($strs);
        $val = [];
        $len = 0;
        for($i=0;$i<$count;$i++){
            $arr = str_split($strs[$i],1);
            $len = max($len,strlen($strs[$i]));
            if($i==0){
                $val = $arr;
            }else{

                for($a = 0;$a < $len ;$a++){

                    if($val[$a] != $arr[$a]){

                        if($a==0){
                            return "";
                        }else{
                            $val = array_slice($val,0,$a);
                        } 
                        
                    }

                }

            }
        }  
        return str_replace(',','',implode(',',$val));   
    }
}
``

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $count = count($strs);
        $val = [];
        $len = 0;
        for($i=0;$i<$count;$i++){
            $arr = str_split($strs[$i],1);
            $len = max($len,strlen($strs[$i]));
            if($i==0){
                $val = $arr;
            }else{

                for($a = 0;$a < $len ;$a++){

                    if($val[$a] != $arr[$a]){

                        if($a==0){
                            return "";
                        }else{
                            $val = array_slice($val,0,$a);
                        } 
                        
                    }

                }

            }
        }  
        return str_replace(',','',implode(',',$val));   
    }
}
```