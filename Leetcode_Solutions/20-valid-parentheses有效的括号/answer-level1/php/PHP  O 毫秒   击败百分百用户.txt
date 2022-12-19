### 解题思路
0
 先拆成数组，然后循环
 左进 左出原则 
### 代码
 
```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {

         if (strlen($s)==0){
            return true;
        }
        $s=chunk_split($s,'1',',');
        $s=explode(',',$s);
        array_pop($s);
       $res=array();
        foreach ($s as $key=>$value){
           switch ($value){
               case "(":
                  $res[]=1;
                  break;
               case ")":
                   if (end($res)!="1"){
                       return false;
                   }
                   array_pop($res);
                   break;
               case "[":
                   $res[]=2;
                   break;
               case "]":
                   if (end($res)!="2"){
                       return false;
                   }
                   array_pop($res);
                   break;
               case "{":
                   $res[]=3;
                   break;
               case "}":
                   if (end($res)!="3"){
                       return false;
                   }
                   array_pop($res);
                   break;
           }

        }
         if ($res){
            return false;
        }
        return true;
        
    }
}
```