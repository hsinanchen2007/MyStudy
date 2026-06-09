```
function getHint($secret, $guess) {
    $a = 0;
    $b = 0;
    $barr = [];
    $smap = [];
    for($i=0;$i<strlen($secret);$i++) // 将$secret转化为键名数组
        $smap[$secret[$i]] = isset($smap[$secret[$i]])?$smap[$secret[$i]]+1:1;
    for($i=0;$i<strlen($secret);$i++){
        if($guess[$i]==$secret[$i]){
            $a++;
            $smap[$guess[$i]]--;
            if($smap[$guess[$i]] === 0) unset($smap[$guess[$i]]);
        }else{
            $barr[] = $guess[$i]; // 收集非公牛
        }
    }
    foreach($barr as $iguess){ //在非公牛数组中匹配母牛
        if(array_key_exists($iguess,$smap)){
            $b++;
            $smap[$iguess]--;
            if($smap[$iguess] === 0) unset($smap[$iguess]);
        }
    }
    return $a."A".$b."B";
}
```
