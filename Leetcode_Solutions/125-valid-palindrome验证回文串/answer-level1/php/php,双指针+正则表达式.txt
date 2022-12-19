# **思路：
1 先把字符串里面字母变成全部小写或大写
2 然后用正则表达式判断是否是字母或数字；**

    function isPalindrome($s) {
        $len = strlen($s);
        $i = 0;
        $j = $len - 1;
        $sl = strtolower($s);
        while($i < $j){
            if(preg_match('/^[0-9a-zA-Z]+$/', $sl[$i]) && preg_match('/^[0-9a-zA-Z]+$/', $sl[$j])){ 
            if($sl[$i] == $sl[$j]){
                $i++;
                $j--;
            }else{
                return false;
            }
            }else if(!preg_match('/^[0-9a-zA-Z]+$/', $sl[$i]) && !preg_match('/^[0-9a-zA-Z]+$/', $sl[$j])){
                $i++;
                $j--;
            }else if(!preg_match('/^[0-9a-zA-Z]+$/', $sl[$i])){
                $i++;
            }else {
                $j--;
            }
        }
        return true;
    }