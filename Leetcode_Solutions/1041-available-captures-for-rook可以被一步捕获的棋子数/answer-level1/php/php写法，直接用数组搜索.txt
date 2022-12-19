题目读起来不要太费劲，理解个大半天，后来去评论去看评论，原来我不是一个人。。。
贴代码，简单简单

class Solution {

    /**
     * @param String[][] $board
     * @return Integer
     */
    function numRookCaptures($board) {
        $len = count($board);
        //找出车的位置i,j  两个for循环，所以要用两次break
        for($i = 0;$i < $len;$i++){
            for($j = 0;$j < $len;$j++){
                if($board[$i][$j] == 'R'){
                    break;
                }
            }
            if($board[$i][$j] == 'R'){
                break;
            }
        }
        $num = 0;
        //然后从车的位置向四个方向找能吃的兵

        //左侧
        $left = $j - 1;
        while($left >= 0){
            if($board[$i][$left] == 'p'){
                $num++;
                break;
            }elseif($board[$i][$left] == 'B'){
                break;
            }else{
                $left--;
            }
        }
        //右侧
        $right = $j + 1;
        while($right < $len){
            if($board[$i][$right] == 'p'){
                $num++;
                break;
            }elseif($board[$i][$right] == 'B'){
                break;
            }else{
                $right++;
            }
        }
        //上边
        $top = $i - 1;
        while($top >= 0){
            if($board[$top][$j] == 'p'){
                $num++;
                break;
            }elseif($board[$top][$j] == 'B'){
                break;
            }else{
                $top--;
            }
        }
        //下边
        $bottom = $i + 1;
        while($bottom < $len){
            if($board[$bottom][$j] == 'p'){
                $num++;
                break;
            }elseif($board[$bottom][$j] == 'B'){
                break;
            }else{
                $bottom++;
            }
        }
        return $num;
    }
}