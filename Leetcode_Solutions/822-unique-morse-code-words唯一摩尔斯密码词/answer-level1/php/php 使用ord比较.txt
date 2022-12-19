如下
```
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function uniqueMorseRepresentations($words) {
        $morse=[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
        $result=[];
       foreach ($words as $value){
           $i=0;
        $str="";
           while ($i<(strlen($value))){
               $str.=$morse[ord($value[$i])-ord(a)];
               $i++;
           }
            array_push($result,$str);
       }
       $result=array_unique($result);
        return  count($result);
    }
}
```