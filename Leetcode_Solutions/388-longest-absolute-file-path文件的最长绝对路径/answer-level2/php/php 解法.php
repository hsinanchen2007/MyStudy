注：php的双引号和单引号的区别问题，简单概括下双引号中的变量可以解析，单引号就是绝对的字符串。
“\n”代表换行符，长度为1
'\n'代表\和n组成的长度为2的字符串。
```
function lengthLongestPath($input) {
    $input .= "\n";
    $max = $path = $len = 0;
    $tmp = '';
    $ret = [];
    for($i=0;$i<strlen($input);$i++){
        if($input[$i]=="\n"){ // 这里只能用双引号
            $retp[$path] = $tmp;
            $len += strlen($retp[$path]);
            if(strpos($tmp,".")!==false){
                $max = max($max,$len+$path);
            }
            $path = 0;
            $len = 0;
            $tmp = '';
        }else if($input[$i]=="\t"){ // 这里只能用双引号
            $len += strlen($retp[$path]);
            $path ++;
        }else{
            $tmp .= $input[$i];
        }
    }
    return $max;
}
```
