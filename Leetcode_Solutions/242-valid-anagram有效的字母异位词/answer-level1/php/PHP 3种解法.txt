# **方法一：自带函数**
执行用时 4ms
内存消耗 18 MB
思路：利用数组记录字符串每个字符的出现次数；利用PHP自带函数实现记录

    function isAnagram($s, $t) {     
        if(strlen($s) != strlen($t)){              //判断两字符串长度是否一样
            return false;
        }
    
        $arr1 = array_count_values(str_split($s));//把字符串变成数组
        $arr2 = array_count_values(str_split($t));//并返回新数组键为字符，值为出现次数
        $length = count($arr1);
        $key = array_keys($arr1);                //获取所有键，并以新数组返回
        
        if($length != count($arr2))
            return false;
        for($i = 0; $i < $length; $i++){
            if($arr1[$key[$i]] != $arr2[$key[$i]])
                return false;
        }
        return true;
    }
**方法一另一种实现**
执行用时 12ms
内存消耗 18.1 MB

    function isAnagram($s, $t) {
        if(strlen($s) != strlen($t))
                return false;
            
        $arr1 = array_count_values(str_split($s));
        $arr2 = array_count_values(str_split($t));
        $length = count($arr1);
            
        if($length != count($arr2))            //若拥有的字符类型数量不一样，数组长度不一样
            return false;
        foreach($arr1 as $charKey => $value){ //以键值对的形式循环计较
            if($arr2[$charKey] != $value) {
                return false;
            }
        }
        return true;
    } 
# **方法二：哈希表**
执行用时 16ms
内存消耗 17.9 MB
思路：利用哈希表记录出现的字符串与对应出现的次数

    function isAnagram($s, $t) {
        $hash = [];
        $count = strlen($s);
        $count2 = strlen($t);
        if ($count2!=$count) {
            return false;
        }
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$s[$i]])) {
                $hash[$s[$i]] = 1;
            } else {
                $hash[$s[$i]]++;       //键为字符，出现一次，自增一次
            }
            
        }
        for ($i=0;$i<$count;$i++) {    
            if(!isset($hash[$t[$i]]))
                return false;  
            
            $hash[$t[$i]]--; 
            if($hash[$t[$i]] < 0)
                return false;      
        }
        return true;
    } 
# **方法三：排序**
执行用时 68ms
内存消耗 21.1 MB
思路：对两字符串重新进行排序，然后进行比较

    function isAnagram($s, $t) {    
            if(strlen($s) != strlen($t))
                return false;
            
            $arr1 = str_split($s);
            $arr2 = str_split($t);
            sort($arr1);
            sort($arr2);     

            return $arr1 == $arr2;
    } 