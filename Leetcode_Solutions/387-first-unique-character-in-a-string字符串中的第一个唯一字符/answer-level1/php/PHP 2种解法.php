# **方法一：哈希表**

    function firstUniqChar($s) {
        $length = strlen($s);
        if($length == 1){
            return 0;
        }else{
            $hash = [];
            for($i = 0; $i < $length; $i++){
                if(!isset($hash[$s[$i]])){
                    $hash[$s[$i]] = 1;
                }else{
                    $hash[$s[$i]]++;
                }
            }
            var_dump($hash);
            for($j = 0; $j < $length; $j++){
                if($hash[$s[$j]] == 1) return $j;
            }
        }
        return -1;
    }

# **方法二：排序+自带函数**

    function firstUniqChar($s) {
        $length = strlen($s);
        if($length == 1) return 0;
        $s = str_split($s);
        $arr = array_count_values($s);
        asort($arr);
        for($i = 0; $i < $length; $i++){
            if($arr[$s[$i]] == 1)
                return $i;
        }
        return -1;
    }