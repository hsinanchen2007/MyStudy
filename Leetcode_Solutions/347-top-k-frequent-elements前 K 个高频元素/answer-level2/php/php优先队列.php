思路：利用php的优先队列，重写compare接口，保持一个最小堆
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function topKFrequent($nums, $k) {
        $times=[];

        foreach($nums as $item){
            if(isset($times[$item])){
                $times[$item]+=1;
            }else{
                $times[$item]=1;
            }
        }

        $queue=new SplPriorityQueue2();
        foreach($times as $key=>$val){
            if($queue->count()<$k){
                $queue->insert($key,$val);
            }else if($val>$times[$queue->top()]){
                $queue->extract();
                $queue->insert($key,$val);
            }
        }

        $ret=[];

        while(!$queue->isEmpty()){
            $ret[]=$queue->extract();
        }

        return $ret;        
    }
}

class SplPriorityQueue2 extends SplPriorityQueue{
    public function compare($a,$b){
        if($a==$b)
            return 0;
        
        return $a>$b?-1:1;
    }
}
```
