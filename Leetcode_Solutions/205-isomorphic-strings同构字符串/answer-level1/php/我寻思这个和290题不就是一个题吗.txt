function isIsomorphic($s, $t) {
        if(strlen($s) != strlen($t))  return false;
        
        $map = [];
        for($i = 0; $i <strlen($s);$i++){
            if(!isset($map[$s[$i]])){
                if(in_array($t[$i],$map)) return false;
                $map[$s[$i]] = $t[$i];
            }else{
                if($map[$s[$i]] != $t[$i]) return false;
            }
        }
        
        return true;
    }