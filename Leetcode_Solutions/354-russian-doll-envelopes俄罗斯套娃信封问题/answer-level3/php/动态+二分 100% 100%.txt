### 解题思路
感谢[@liweiwei1419](/u/liweiwei1419/)的二分解法，虽然其实还不完全懂

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $envelopes
     * @return Integer
     */
    function maxEnvelopes($envelopes) {
                if(empty($envelopes)) return 0;
        sort($envelopes);//排序第一维

        $dup_len = 1;//第一维相同子数组的个数
        $starting_index = 0;//第一位相同子数组的开始index
        for($i=1;$i<count($envelopes);$i++){
            if($envelopes[$i][0] == $envelopes[$i-1][0]){
                $dup_len++;
            }
            else{
                if($dup_len>1){
                    //从原数组中切出子数组第一位数相同的子数组
                    $sorting_array = array_slice($envelopes,$starting_index,$dup_len);
                    //降幂排序数组
                    rsort($sorting_array);
                    //插入并覆盖原数组
                    array_splice($envelopes, $starting_index, $dup_len, $sorting_array);
                }
                $starting_index = $i;
                $dup_len = 1;
            }
        }

        //循环完毕再次检查第一位相同子数组的个数是否大于一，因为有可能这几个数字在数组最后几位，没有机会判别
        if($dup_len>1){
            $sorting_array = array_slice($envelopes,$starting_index,$dup_len);
            rsort($sorting_array);
            array_splice($envelopes, $starting_index, $dup_len, $sorting_array);
        }


        /*----- 原始动态解，大部分情况下都会超时，不超时的几次也是将近5000毫秒的用时
        $max = 0;
        $dp = [];
        for($i = 0; $i < count($envelopes); $i++){
            $dp[$i] = 1;
            for($j = 0; $j < $i; $j++){
                if($envelopes[$j][0] < $envelopes[$i][0] && $envelopes[$j][1] < $envelopes[$i][1]){
                    $dp[$i] = max($dp[$i], $dp[$j] + 1);
                    print_r($dp);
                } 
            }
            $max = max($dp[$i], $max);

        }

        return $max;
        */

        //二分法
        //设子数组第一个数字为宽度，第二个为高度
        //当前套娃组，只记录高度
        $stacked_envs = [];
        $stacked_envs[0] = $envelopes[0][1];

        //表示套娃组的最后一个已经赋值元素的索引
        $last_env_index = 0;

        for ($i = 1; $i < count($envelopes); $i++) {
            $target = $envelopes[$i][1];

            //如果当前子数组可以套入前一个
            if ($target > $stacked_envs[$last_env_index]) {
                $last_env_index++;
                $stacked_envs[$last_env_index] = $target;
            } else {
                $left = 0;
                $right = $last_env_index;

                while ($left < $right) {
                    $mid = floor(($left + $right)/2);
                    if ($stacked_envs[$mid] < $target) {
                        $left = $mid + 1;
                    } else {
                        $right = $mid;
                    }
                }

                $stacked_envs[$left] = $target;
            }

        }
        return $last_env_index + 1;

    }
}
```