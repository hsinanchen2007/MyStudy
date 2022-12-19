思路：利用php的优先队列SplPriorityQueue，维持一个有k个元素的最大堆。
```php
class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
        if($k==0){
            return [];
        }
        $queue=new SplPriorityQueue();
    
        foreach($arr as $key=>$val){
            if($queue->count()<$k){
                $queue->insert($key,$val);
            }else if($val<$arr[$queue->top()]){
                $queue->extract();
                $queue->insert($key,$val);
            }
        }

        $ret=[];

        while(!$queue->isEmpty()){
            $ret[]=$arr[$queue->extract()];
        }

        return $ret;
    }
}
```
