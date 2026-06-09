### 解题思路
单调双端队列的实现，思路参考这位老哥的，看了就明白了，写的非常好
[双向队列解决滑动窗口最大值
](https://leetcode-cn.com/problems/sliding-window-maximum/solution/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-2/)

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function maxSlidingWindow($nums, $k) {
        //异常值判断
        if(count($nums)<1) return $nums;

        //队列存储对应数的下标index
        $queue = [];

        //结果输出
        $result = [];

        for($i=0;$i<count($nums);$i++){
            //如果队列有值(值都是下标)，并且队尾的元素小于等于当前遍历到的元素，就把队尾元素出队，直至队尾元素大于当前元素停止
            while (!empty($queue) && $nums[end($queue)]<=$nums[$i]){
                array_pop($queue);
            }

            //向队尾添加元素(值下标)
            $queue[] = $i;

            //如果队首(队列最大的元素)的下标小于当前窗口的左边界，说明队首元素是无效的，需要把队首元素出队
            if($queue[0] < $i+1-$k){
                array_shift($queue);
            }

            //如果窗口已经形成，就把窗口最大的元素(队首)放入结果集
            if($i+1>=$k){
                $result[] = $nums[$queue[0]];
            }
        }

        return $result;
    }
}
```