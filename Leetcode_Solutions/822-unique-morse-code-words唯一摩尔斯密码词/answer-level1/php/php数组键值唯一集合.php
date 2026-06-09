思路：利用集合唯一性，php键值数组
```php
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    private $key=['a'=>".-",'b'=>"-...",'c'=>"-.-.",'d'=>"-..",'e'=>".",'f'=>"..-.",'g'=>"--.",'h'=>"....",'i'=>"..",'j'=>".---",'k'=>"-.-",'l'=>".-..",'m'=>"--",'n'=>"-.",'o'=>"---",'p'=>".--.",'q'=>"--.-",'r'=>".-.",'s'=>"...",'t'=>"-",'u'=>"..-",'v'=>"...-",'w'=>".--",'x'=>"-..-",'y'=>"-.--",'z'=>"--.."];

    function uniqueMorseRepresentations($words) {
        $res=[];
        foreach($words as $item){
            $res[$this->createPWD($item)]=1;
        }

        return sizeof($res);
    }

    //创建每个单词对应的摩斯密码
    function createPWD($str){
        $len=strlen($str);
        $ret="";
        for($i=0;$i<$len;$i++){
            $ret.=$this->key[substr($str,$i,1)];
        }
        return $ret;
    }
}
```
