### 解题思路
开始没理解题意浪费了很多时间，该题是存在一个整数x可以将整副牌分成一组或多组，每组的要求是组内的元素相等。然后x不小于2.
也就是说整副牌的元素相同的个数存在大于等于2的公约数即可。

第一步：取元素相等的个数
第二步：将获取的个数取公约数

获取公约数这个是从2开始判断的，等找到最佳方法再来优化。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $deck
     * @return Boolean
     */
    function hasGroupsSizeX($deck) {
        // 存在一个不小于2的数字x
        // 将整副牌分成一组或多组：
        // 每组都有x张牌
        // 组内所有牌都写着相同的数字


        // 分析：统计$deck内每个元素出现的次数，如果存在公约数大于等于2则说明至少存在一个数字x可以将$deck分成x组且组内元素大小相等

        // 步骤1，获取每个元素出现的次数
        $item_times = $this->get_item_times($deck);
        // 有出现一次的元素则直接返回false
        if (min($item_times) < 2) {
            return false;
        }

        // 步骤2，取公约数，比如 3 3 2,   2 2 2,   2 4
        $gcd = $this->get_gcd($item_times);
        if ($gcd < 2) {
            return false;
        }

        return true;
    }

    /**
    * @deck 给定的数组
    * @return 每个元素出现的次数的数组
    */
    public function get_item_times($deck)
    {
        $item_times = [];
        while(count($deck) > 0) {
            // 取第一个元素及次数默认1
            $item = $deck[0];
            $times = 1;
            $count = count($deck);
            for ($i = 1; $i < $count; $i++) {
                if ($item == $deck[$i]) {
                    ++$times;// 次数加一
                    unset($deck[$i]);// 去掉相等的元素
                }
            }
            unset($deck[0]);// 去掉第一个元素
            $deck = array_values($deck);// 重新排序
            $item_times[] = $times;
        }

        return $item_times;
    }

    /**
    * @item_times 数组：元素个数出现次数
    * @return 最大公约数
    */
    public function get_gcd($item_times)
    {
        $min_item = min($item_times);// 最少的次数，最大公约数必须小于等于这个值
        $gcd = 1; // 最大公约数
        $count = count($item_times);

        for ($i = 2; $i <= $min_item; $i++) { // 从2开始判断
            $len = 0; // 判断比较到了第几个
            for ($n = 0; $n < $count; $n++) { // 从第一个元素开始判断
                if ($item_times[$n] % $i != 0) { // 求余
                    break;
                }
                ++$len;
            }
            if ($len == $count) { // 如果比较到了$count个说明比完了
                $gcd = $i;
            }
        }

        return $gcd;
    }
}
```