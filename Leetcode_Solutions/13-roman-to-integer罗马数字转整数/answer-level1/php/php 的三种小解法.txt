初解法1：
```
function romanToInt($s) {
        $value = [900,400,90,40,9,4,1000,500,100,50,10,5,1];
        $str = ['CM','CD','XC','XL','IX','IV','M','D','C','L','X','V','I'];
        $int = 0;
        for($i=0;$i<count($value)&&strlen($s)>0;$i++){
            $int += substr_count($s,$str[$i])*$value[$i];
            $s = str_replace($str[$i],"",$s);
        }
        return $int;
    }
```
初解法2：
```
function romanToInt($s) {
        $value = [900,400,90,40,9,4,1000,500,100,50,10,5,1];
        $str = ['CM','CD','XC','XL','IX','IV','M','D','C','L','X','V','I'];
        $int = 0;
        while(strlen($s)>0){
            for($i=0;$i<count($value);$i++){
                if(strpos($s, $str[$i]) === 0){
                    $int += $value[$i];
                    $s = substr($s,strlen($str[$i]));
                    break;
                }
            }
        }
        return $int;
    }
```
解法3：
```
function romanToInt($s) {
        $rule = ['M'=>1000,'D'=>500,'C'=>100,'L'=>50,'X'=>10,'V'=>5,'I'=>1];
        $int = 0;
        for($i=0;$i<strlen($s);$i++){
            if(!empty($rule[$s[$i+1]] && $rule[$s[$i+1]]>$rule[$s[$i]])){
                $int += $rule[$s[$i+1]]-$rule[$s[$i]];
                $i++;
            }else{
                $int += $rule[$s[$i]];
            }
        }
        return $int;
    }
```