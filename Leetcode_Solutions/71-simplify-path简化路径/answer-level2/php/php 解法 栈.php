```
function simplifyPath($path) {
    $stack = [];
    $parr = explode("/",$path);
    foreach($parr as $p){
        if($p!='' && $p!='.' && $p!='..'){
            array_push($stack,$p);
        }
        if(!empty($stack) && $p =='..'){
            array_pop($stack);
        }
    }
    if(empty($stack)) return "/";
    $ans = '';
    foreach($stack as $p){
        $ans .= '/'.$p;
    }
    return $ans;
}
```
