### 解题思路
1 统计给出数组中每个数组出现的频次，计入`$map`中
2 将`$map`放入 `SplMaxHeap` 数据结构中，并重写比较函数
3 统计数据`$map`经过“堆”处理后，每次弹出的根节点就是最大值
4 将依次弹出的`k`个元素保存到变量`$res`中并返回

### 代码

```php
class MySimpleHeap extends SplMaxHeap   
{ 
    // 重写父类的比较方法，根据频次值比较
    public function  compare( $arr1, $arr2 ) { 
        $values1 = array_values($arr1);
        $values2 = array_values($arr2);         
        if ($values1[0] === $values2[0]) return 0;
        return $values1[0] < $values2[0] ? -1 : 1;
    } 
}

class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function topKFrequent($nums, $k) {
    
        $map = [];
        foreach($nums as $v){
            if(!empty($map) && in_array($v,array_keys($map))){
                $map[$v] ++;
            }else{
                $map[$v] = 1;
            }
        }
        
        // 将统计出的结果加入到 最大堆 结构中
        $heap = new MySimpleHeap();
        foreach($map as $key=>$val){
            $heap->insert([$key=>$val]);
        }

        // 依次取出k个元素放入结果数组中
        $res = [];
        for($i=0;$i<$k;$i++){
            $res[] = array_keys($heap->extract())[0];
        }
        
        return $res;
    } 
}
```