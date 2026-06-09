### 解题思路
题目真心看不懂。看了题解后终于明白了。感谢 [@salmonl](/u/salmonl/)

1. 每 ping 一次把时间 t 入队
2. 从队头开始检查，当前 t 和队头时间间隔大于 3000ms 的出队 (保留等于 3000ms 的，如 1ms 和 3001ms)
3. 队列中剩下的元素就是需要统计的请求，计算长度即可。
4. 使用标准库函数可显著提升效率。

### 代码

```php
class RecentCounter
{
    protected $queue;

    /**
     */
    function __construct()
    {
        $this->queue = new SplQueue();
    }

    /**
     * @param Integer $t
     * @return Integer
     */
    function ping($t)
    {
        while ($this->queue->count() && $this->queue->bottom() + 3000 < $t) {
            $this->queue->dequeue();
        }
        $this->queue->enqueue($t);

        return $this->queue->count();
    }
}
```