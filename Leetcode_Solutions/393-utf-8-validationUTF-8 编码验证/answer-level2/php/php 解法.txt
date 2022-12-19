```
function validUtf8($data) {
    $byteLength = 0;
    $binData = [];
    foreach($data as $num){
        $binRep = decbin($num);
        $binRep = (strlen($binRep)>=8) ? substr($binRep,0,8) : substr("00000000",strlen($binRep)%8).$binRep;
        
        if($byteLength == 0){
            for($i=0;$i<strlen($binRep);$i++){
                if($binRep[$i] == '0') break;
                $byteLength++;
            }
            if($byteLength == 0) continue;
            if($byteLength>4 || $byteLength==1) return false;
            //初始情况下$byteLength==1结构是这样10xxxxxx，实际情况是0xxxxxxx
        }else{
            if(!($binRep[0] == '1' && $binRep[1] == '0')){
                return false;
            }
        }
        $byteLength--;
    }
    return $byteLength == 0;
}
```
