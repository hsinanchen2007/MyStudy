### 解题思路
清晰简单思路，总糖果数按照降幂往下减，顺序按照取余数递增

### 代码

```php
class Solution {

    /**
     * @param Integer $candies
     * @param Integer $num_people
     * @return Integer[]
     */
    function distributeCandies($candies, $num_people) {
        
        $index = 1;//发糖顺位初始值

        //开始index,个数,每个元素的赋值
        $kids_with_candies = array_fill(0, $num_people, 0);//按小朋友数量设置数组，初始值为0

        //只要还有糖就一直发
        while ($candies >= 0){
            $cur_index = ($index-1) % $num_people;//当前应该得到糖那个小朋友的顺位
            if($index>$candies){//如果剩余糖果不足支付应发的，则把剩下的都给那个小朋友
                $kids_with_candies[$cur_index] += $candies;
            }else{
                $kids_with_candies[$cur_index] += $index;
            }
            //以上if else可缩写为：
            //$kids_with_candies[$cur_index] += $candies >= $index?$index:$candies;
            $candies -= $index;
            $index++;
            
        }

        return $kids_with_candies;
    }
}
```