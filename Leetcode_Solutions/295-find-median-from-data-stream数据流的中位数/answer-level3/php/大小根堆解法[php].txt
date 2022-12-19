### 解题思路
利用大小根堆。
大根堆保存所有小于等于中位数的数字集合
小根堆保存所有大于中位数的数字集合。
步骤如下：
1、数字先写入大根堆
2、将大根堆中最大的数字写入小根堆
3、如果是奇数次的话，就将小根堆中的顶部的数写入大根堆，保持大根堆比小根堆多一个数。
4、查找中位数的话，如果是偶数，那么大小跟对的顶部除以2便是，如果奇数的话，就是大根堆的顶部元素。

### 代码

```php
class MedianFinder {
    //利用spl建立大小根堆
    private $min_heap;
    private $max_heap;
    private $count;

    /**
     * initialize your data structure here.
     */
    function __construct() {
        $this->min_heap = new SplMinHeap();
        $this->max_heap = new SplMaxHeap();
        $this->count = 0;
    }

    /**
     * @param Integer $num
     * @return NULL
     */
    function addNum($num) {
        $this->count++;
        //先写入大根堆
        $this->max_heap->insert($num);
        //将大根堆中最大的数写入小根堆
        $this->min_heap->insert($this->max_heap->extract());
        //如果是奇数次的话，就将第奇数个数字写入大根堆
        if($this->count%2!=0){
            $this->max_heap->insert($this->min_heap->extract());
        }
    }

    /**
     * @return Float
     */
    function findMedian() {
        //如果是偶数的话，就大小根堆顶部各取一个数，然后除以2
        if($this->count%2==0){
            return ($this->min_heap->top()+$this->max_heap->top())/2;
        }
        //奇数的话就是大根堆的顶部的数了
        return $this->max_heap->top();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * $obj = MedianFinder();
 * $obj->addNum($num);
 * $ret_2 = $obj->findMedian();
 */
```