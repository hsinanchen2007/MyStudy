根据大佬们的算法,总结下来的
使用foreach循环,和其他双指针写法不同
执行用时 :220 ms, 在所有 php 提交中击败了 91.78%的用户
内存消耗 :24.8 MB, 在所有 php 提交中击败了6.45%的用户
速度还算是很快了,应该还有可优化的地方,希望后来人给出修改意见,谢谢
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        $rt = [];
        $arr = [];
        if(count($nums)<3){
            return $rt;
        }
        foreach($nums as $v){
            if(isset($arr[$v])){
                $arr[$v]++;
            }else{
                $arr[$v] = 1;
            }
        }
        if(isset($arr[0])){
            if($arr[0] > 2){
                $rt['0,0,0'] = [0,0,0];
            }else{
                $arr[0]=1;
            }
        }
        ksort($arr);
        
        foreach($arr as $k=>$v){
            if($k>0){
                break;
            }
            $need = 0 - $k;
            foreach($arr as $x=>$z){
                $d = $need - $x;
                if(isset($arr[$d])){
                    if(($x == $k && $arr[($x)]<2) || ($k == $d && $arr[$d]<2) || ($x == $d && $arr[$d]<2)){
                        continue;
                    }
                    $tmp = [$x,$k,($x+$k)*-1];
                    sort($tmp);
                    $tmp_str = implode(",",$tmp);
                    $rt[$tmp_str] = $tmp;
                }
            }
        }
        $rt = array_values($rt);
        return $rt;
    }
}
```
