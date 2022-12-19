### 解题思路
先贴代码，思路再补充。

### 代码

```php
class Solution {
    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
        $heap=[];
        for($i=0;$i<$k;$i++){
            $heap[$i+1]=$arr[$i];
        }
        $this->buildHeap($heap,count($heap));
        for($i=$k;$i<count($arr);$i++){
            if($arr[$i]<$heap[1]){
                $heap[1]=$arr[$i];
                $this->heapify($heap,count($heap),1);
            }
        }
        unset($heap[0]);
        return $heap;
    }

    function buildHeap(&$arr,$n){
        for($i=floor($n/2);$i>=1;$i--){
            $this->heapify($arr,$n,$i);
        }
    }

    function heapify(&$arr,$n,$i){
        while (true){
            $max_pos = $i;
            if($i*2<=$n && $arr[$i*2]>$arr[$i]) $max_pos=$i*2;
            if($i*2+1<=$n && $arr[$i*2+1]>$arr[$max_pos]) $max_pos=$i*2+1;
            if($i==$max_pos) break;
            $this->swap($arr,$max_pos,$i);
            $i=$max_pos;
        }
    }

    function swap(&$arr,$i,$j){
        list($arr[$i],$arr[$j]) = [$arr[$j],$arr[$i]];
    }
}
```