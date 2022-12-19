其实还是比较简单的，只是PHP很容易超时。
```
class StreamChecker {
    public $string;
    function __construct($words) {
        $this->arr = array_unique($words);
    }
    function query($letter) {
        if(in_array($letter,$this->arr)){$this->string.=$letter;return true;}
        $this->string.=$letter;
        if(in_array($this->string,$this->arr)){return true;}
        foreach($this->arr as $k=>$v){
           if(substr($this->string,-strlen($v))==$v){
               return true;
           }
        }
        return false;
    }
}
```
