两个串都转成数组

设置空数组，如果有#则删除最后一个元素，通过array_splice或者array_pop都行

function backspaceCompare($S, $T) {
        $s_arr = str_split($S);
        $t_arr = str_split($T);
        $shed = [];
        $tshed = [];
        foreach($s_arr as $rv) {
            if($rv == '#') {
                //删除倒数第一个
                 array_splice($shed,-1);
            } else {
                array_push($shed,$rv);
            }
        }
        foreach($t_arr as $rv) {
            if($rv == '#') {
                //删除倒数第一个
                 array_splice($tshed,-1);
            } else {
                array_push($tshed,$rv);
            }
        }
        if($tshed == $shed) {
            return true;
        }else {
            return false;
        }
    }
