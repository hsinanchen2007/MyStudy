步骤分析

class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
           $numArr =[];/**设置一个空数组*/
        foreach($nums as $key =>$val) { /**foreach循环遍历*/
            $did =$target-$val;    /**我们要实现的和减去数组整数值*/
            if(!isset($numArr[$did])){   /**判断numArr数组是否有$did key的值    没有则把nums中的key放在numArr的val中，nums的val放numArr的key中，也就是调换一下*/
                $numArr[$val]=$key;   /**key val 调换*/
                continue;    /**结束当前循环，继续下一轮循环。跟return结束循环不一样*/
            }
            return [$numArr[$did],$key];  /**返回结果  分析：既然能走到这里那么$numArr[$did]是有值的，也就是说他的值就是nums的key,然后在加上当前key*/

          /**希望对后面的读者有帮助*/
        }
        
    }

}