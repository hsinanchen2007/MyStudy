php解法一：
class Solution {

    /**
     * @param Integer $c
     * @return Boolean
     */
    function judgeSquareSum($c) {
        //为0的情况比较特殊，单独处理
        if($c==0){
            return true;
        }
        for($i=0;$i*$i<$c;$i++){
        $b=$c-$i*$i;
        if($this->binSearch2(0,$b,$b)){
            return true;
        }
        }
        return false;
    }

     //二分查找法（非递归方法）
    public function binSearch2($low,$height,$search){
       if($low>$height){
        return false;
       }
 
        //floor() 函数向下舍入为最接近的整数。注意这里需要取整
        $middle=intval($low+($height-$low)/2);
        if($middle*$middle==$search){
          return true;
        }
        if($middle*$middle>$search){
          return $this->binSearch2($low,$middle-1,$search);
        }else{
          return $this->binSearch2($middle+1,$height,$search);
        }
      
      //数组不存在,或者没有此数都算查找失败
      return true;
    } 
}


php解法二：

class Solution {

    /**
     * @param Integer $c
     * @return Boolean
     */
    function judgeSquareSum($c) {
                $l=0;
        $r=floor(sqrt($c));
        while($l<=$r){
            if($c-$l*$l==$r*$r){
                return true;
            }elseif($c-$l*$l>$r*$r){
    /*浮动的范围在[l,r]之间，只能l递增或者r递减*/
                $l++;
            }elseif($c-$l*$l<$r*$r){
                $r--;
            }
        }

        return false;
    } 
}


如果这样写就超出时间限制：因为这种解法是错误的,
//浮动的范围在[l,r]之间，只能l递增或者r递减

class Solution {

    /**
     * @param Integer $c
     * @return Boolean
     */
    function judgeSquareSum($c) {
               $l=0;
        $r=floor(sqrt($c));
        while($l<=$r){
            if($c-$l*$l==$r*$r){
                return true;
            }elseif($c-$l*$l>$r*$r){
                $r++;
            }elseif($c-$l*$l<$r*$r){
                $l--;
            }
        }

        return false;
    } 
}

