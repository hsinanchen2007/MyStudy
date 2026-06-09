
思路是：每到一个地方nums[i] 我们只有两个状态，偷 或者 不偷  另一个是 隔开选取(不能连续作案)
根据这个我们画出从[i, 0]的递归状态

                                          rob(7)
                            0(不偷)/                   \1(偷)
                      max(rob(6)                     rob(5)+w[7])
                     0/        \1                     0/   \1
            max(rob(5),         rob(4)+w[6])    max(rob(4),  rob(3) + w[5])
              0/      \1
        max(rob(4),     rob(3)+w[5])
       0/         \1
    max(rob(3),   rob(2) + w[4])


从上面我们基本画出了整个计算过程
**从中得出大概的伪代码**
__maxProfit = max(rob($i-1)不偷, rob(i-2) + profit+w[i]);__
**这个也称为"状态方程"**
但是发现有一些结果是重复计算的， 例如 rob(4)计算了多次      rob(3)+w[5]计算了多次
如果按照上面递归实现，时间复杂度为2^n  (n的深度)

那么如何优化呢？ 将重叠子问题记录下来， 不需要多次递归重复动作
**动态规划核心或者就是为了优化这个重叠子问题**
我们将例如i=4 时 可以取到最大的价值存入数组[3]中，下次在访问到(i=4)时我们直接取值即可
下面的代码就是实现这一思路
自底向上通过迭代计算，直到最后一个元素的最大价值即是结果

时间复杂度O(n), 空间复杂度O(n)

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function rob($nums) {
        $len = count($nums);
        if (!$len) return 0;
        if ($len==1) return $nums[0];
        if ($len==2) return max($nums[0], $nums[1]);

        $dp = [];
        $dp[-1] = 0;
        $dp[-2] = 0;

        for ($i=0; $i<$len; $i++) {
            $dp[$i] = max($dp[$i-1], $dp[$i-2]+$nums[$i]);
        }
        
        return $dp[$len-1];
    }
}

//还可以在空间复杂度上进行优化 
//题中结果影响是 当前max(不偷前一天的价值,  偷+前两天的价值)
//我们只需要记录的是 前一天  和前两天的价值即可   而不需要用一个n长度数组存储每一天的结果

//时空复杂度O(n)  O(1)
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function rob($nums) {
        $len = count($nums);
        if (!$len) return 0;
        if ($len==1) return $nums[0];
        if ($len==2) return max($nums[0], $nums[1]);

        $preOneDay = $preTwoDay = 0;

        for ($i=0; $i<$len; $i++) {
            $todayMax = max($preOneDay, $preTwoDay+$nums[$i]);
            $preTwoDay = max($preTwoDay, $preOneDay);
            $preOneDay = max($preOneDay,$todayMax);
        }
        
        return $todayMax;
    }
}

看了几个视频+做了几道简单难度的dp题之后，发现解题思路就是从画出递归图(当然这是我的方法) 然后通过递归图得出状态方程
通过状态看是存储dp数组还是几个变量(例如这道题不能连续偷 那么有影响的就是 前一天的最大价值 && 两天前的最大价值)
我们只需要这两个变量即可记录状态


目前只是算入门的小菜ji， 坚持学习，坚持刷题， 算法和数据结构总会提升上去  一起进步  



求动力~ 动动小手给个star  [github](https://github.com/wuye251/algorithm)