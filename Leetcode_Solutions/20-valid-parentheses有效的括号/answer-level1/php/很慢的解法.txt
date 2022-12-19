1. 递归消消乐。。
```
function isValid($s) {
      $s = str_replace(['()','[]','{}'],'',$s,$count);
      if($count==0){
          return strlen($s)==0;
      }else{
          return $this->isValid($s);
      }
 }
```

2. 循环消消乐。。
```
function isValid($s) {
    while(true){
        $s = str_replace(['()','[]','{}'],'',$s,$count);
        if($count==0){
            return strlen($s)==0;
        }
    }
}
```