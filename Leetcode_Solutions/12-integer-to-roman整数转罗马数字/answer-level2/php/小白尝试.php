### 解题思路
列出可能出现的字符数组和对应的数字

由大到小一次循环

### 代码
    function intToRoman($num) {
        $model=[1000 => "M" ,900=>"CM",500=>"D",400=>"CD",100=>"C",90=>"XC",50=>"L",40=>"XL",10=>"X",9=>"IX",5=>"V",4=>"IV",1=>"I"];
        
        $res = '';
        foreach($model as $key=>$value){

            while($num>=$key){
                $num -= $key;
                $res .= $value;
            }

        }
        return $res; 
    }

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($num) {
        $model=[1000 => "M" ,900=>"CM",500=>"D",400=>"CD",100=>"C",90=>"XC",50=>"L",40=>"XL",10=>"X",9=>"IX",5=>"V",4=>"IV",1=>"I"];
        
        $res = '';
        foreach($model as $key=>$value){

            while($num>=$key){
                $num -= $key;
                $res .= $value;
            }

        }
        return $res; 
    }
}
```