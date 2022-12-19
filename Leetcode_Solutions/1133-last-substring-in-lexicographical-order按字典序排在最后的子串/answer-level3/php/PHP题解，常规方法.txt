先寻找字符串中最大单词，再算出其最长子串，然后往后推做自然排序。
PS：题解运行是有BUG的，测试运行通过，实际提交输出不同。
```
class Solution {
function lastSubstring($s) {
        $num=0;
        $nums=0;
        for($i=122;$i>96;$i--){
            $char = chr($i);
            $res = strchr($s,$char);
            if($res){
                $s=strchr($s,$char);
               for($j=0;$j<strlen($s);$j++){
                    if($s[$j]==$char){
                        $nums++;
                    }else{
                        $num = $num>=$nums?$num:$nums;
                        $nums=0;
                    }
                }
                break; 
            }  
        }
        $str='';
         for($i=0;$i<$num;$i++){
             $str.=$char;
         }
       $ss = explode($str,$s);
        $arr[]=$s;
        for($i=1;$i<count($ss);$i++){
           $arr[]=$str.$ss[$i];
        }
        natsort($arr);
      return end($arr);
    }
}
```
另外我看一些人的题解是错误的，竟然也写上来。。。
