栈：可以当成上子弹，后进先出，先进入到栈底
设置一个数组，字符串str_split转换成数组后进行遍历
每次添加时比较是否与栈顶元素相同

若相同则array_pop
若不相同则插入新元素



 function removeDuplicates($S) {
        $shed = [];
        $m_ar = str_split($S); 
        foreach($m_ar as $v) {
            if($v == end($shed)) {
                array_pop($shed);
            } else {
                array_push($shed, $v);
            }
        }
        $shed = implode("", $shed);
        return $shed;
    }