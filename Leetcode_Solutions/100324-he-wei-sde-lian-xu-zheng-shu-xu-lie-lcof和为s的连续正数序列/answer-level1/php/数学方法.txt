
因为是连续的正整数，所以就是一个差为1的等差数列和要为target的问题
假定有n个连续数之和为target；
a1+a2+...+an = targer 用等数列求和公司就可以知道a1=target-(n(n-1)/2)/n
然后循环n就可以知道a1了 ，注意下a1一定要是整数，然后如果a1小于1就退出循环
最后要求的排序的话肯定项越多，a1越小，所以最后对数组反转下就好了
```
class Solution {

    /**
     * @param Integer $target
     * @return Integer[][]
     */
    function findContinuousSequence($target) {
        $result =[];
        for($i=2;;$i++){
            $tmp = [];
            $startNum = ($target-($i*($i-1))/2)/$i;
            //对startNum向下取整，有小数的不行
            $startNumFloor = floor($startNum);
            if(($startNum-$startNumFloor)>0 ){
                continue;
            }
            if($startNum<1){
                break;
            }
            for($j=0;$j<$i;$j++){
                $tmp[] = $startNum+$j;
            }
            $result[] = $tmp;
        }
        //对$result进行反转，
        $result = array_reverse($result);
        return $result;
    }
}
```
