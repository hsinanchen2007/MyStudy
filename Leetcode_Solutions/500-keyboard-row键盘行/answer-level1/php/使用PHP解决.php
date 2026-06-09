```
class Solution {

    /**
     * @param String[] $words
     * @return String[]
     */
    function findWords($words) {
        //将a-z字母所在键盘的行生表示为如下数组
        $map = [2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3];
        
        $data = [];
        foreach($words as $item){
            //将单词转换为小写
            $str = strtolower($item);
            
            //找出单词第一个字母在键盘的第几行
            $line = $map[ord($str[0]) - 97];
            $is_right = true;
            for ($i = 0; $i < strlen($str); $i++){
                $str_line = $map[ord($str[$i]) - 97];

                if($line != $str_line){
                    //不符合条件的单词不记录
                    $is_right = false;
                    break;
                }
            }
            
            //将符合条件的单词加入data数组
            if($is_right){
                array_push($data,$item);
            }
        }
        
        return $data;
    }
}
```
