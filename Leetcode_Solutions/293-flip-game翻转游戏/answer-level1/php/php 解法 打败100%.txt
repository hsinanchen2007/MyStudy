```
    function generatePossibleNextMoves($s) {
        $res = array();
        for ($i=0,$j=1 ;$i<strlen($s);$i++,$j++){
            $str    =   !empty($s[$j]) ?  $s[$i].$s[$j] : '';
            if($str==='++'){
                $res []    =   substr_replace($s,'--',$i,2);
            }
   
        }
        return $res;
    }
```
