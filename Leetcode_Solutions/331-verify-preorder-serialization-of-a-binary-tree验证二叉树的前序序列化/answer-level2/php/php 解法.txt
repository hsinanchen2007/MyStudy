```
function isValidSerialization($preorder) {
    $prearr = explode(",",$preorder);
    $n = 1; // 当前层的所有节点数
    while(true){
        $node = 0; // 非空节点数
        for($i=0;$i<$n;$i++){
            if($prearr[0]!='#') $node++;
            array_shift($prearr);
        }
        $n = $node * 2;
        if($n==0 && count($prearr)>0) return false;
        if($n > count($prearr)){
            return false;
        }else if($n == count($prearr)){
            return true;
        }
    }
}
```
