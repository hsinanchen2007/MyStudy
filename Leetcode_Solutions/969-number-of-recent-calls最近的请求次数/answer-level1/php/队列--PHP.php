### 解题思路
使用队列
算法：
0、每ping一次把t入队
1、从队头开始检查，当前t和队头x时间间隔大于3000ms的出队
2、队列中剩下的元素就是需要统计的请求，计算长度即可。

### 性能
执行用时 :264 ms, 在所有 php 提交中击败了88.68%的用户
内存消耗 :26.5 MB, 在所有 php 提交中击败了76.00%的用户

### 代码

```php
class RecentCounter {
    /**
     */
    function __construct() {
        $this->queue = [];
    }
  
    /**
     * @param Integer $t
     * @return Integer
     */
    function ping($t) {
        array_push($this->queue, $t);
        while ($t - current($this->queue) > 3000) {
            array_shift($this->queue);
        }

        return count($this->queue);
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * $obj = RecentCounter();
 * $ret_1 = $obj->ping($t);
 */
```