```
function evalRPN($tokens) {
    $stack = [];
    foreach($tokens as $token){
        switch($token){
            case "+":
                array_push($stack,array_pop($stack)+array_pop($stack));
                break;
            case "-":
                array_push($stack,-array_pop($stack)+array_pop($stack));
                break;
            case "*":
                array_push($stack,array_pop($stack)*array_pop($stack));
                break;
            case "/":
                $tmp = array_pop($stack);
                array_push($stack,intval(array_pop($stack)/$tmp));
                break;
            default:
                array_push($stack,(int)$token);
        }
    }
    return array_pop($stack);
}
```
