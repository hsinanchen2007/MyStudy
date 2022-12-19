```
function compareVersion($version1, $version2) {
    $v1 = explode(".",$version1); // 以“.”分割，转成数组。
    $v2 = explode(".",$version2); 
    $i = 0;
    while($i<count($v1) && $i<count($v2)){
        if((int)$v1[$i]>(int)$v2[$i]){
            return 1;
        }else if((int)$v1[$i]<(int)$v2[$i]){
            return -1;
        }
        $i++;
    }
    while(isset($v1[$i])){//如果$v1没有遍历完，将进行一下操作
        if((int)$v1[$i]>=1) return 1;
        $i++;
    }
    while(isset($v2[$i])){//如果$v2没有遍历完，将进行一下操作
        if((int)$v2[$i]>=1) return -1;
        $i++;
    }
    return 0;
}
```
