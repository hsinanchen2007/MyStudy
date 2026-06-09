### 解题思路
##### 原始思路： 
看完题目之后第一时间想到的是先升序**排序**，然后根据下标来判断前面有多少个数字就可以了。
转念一想，这样的话，重复的数字也会被分配一个新的下标，导致取值有问题。  
所以需要加入后续处理，**去重**，并且**保留最小的下标**（因为相同的值是并列的，所以保留最小的就可以得出小于此数字的个数）。 
从1开始，到最大值的for循环，每个数值和前一个做比较，不相等的时候保留此时的下标和数值。 
做完上一步后，开始for循环在去重后的数组里查找值，然后计算个数后赋值给空数组，最后返回。

##### 当前代码思路：
上一个思路还没实现，就想到了用php自身的数组函数 **array_flip** 来处理,这样利用本身值的特性就成功去重了。
但是有一个问题，array_flip函数在遇到相同键值的情况下，只会保留**最后一个键名**，所以根据这个情况，把排序变成**降序排列**，再做一次计算，就可以得到准确数值。
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function smallerNumbersThanCurrent($nums) {
        $tmp_arr = $nums;
        rsort($tmp_arr);
        $tmp_arr = array_flip($tmp_arr);
        $length = count($nums);
        foreach ($tmp_arr as $key => $value) {
            $tmp_arr[$key] = $length - 1 -$tmp_arr[$key];
        }
        $arr = [];
        foreach ($nums as $value) {
            $arr[] = $tmp_arr[$value];
        }
        return $arr;
    }
}
```

### 记录
![记录.png](https://pic.leetcode-cn.com/afee691f1dcbe7a9e2e775c920816a735ba13037036280c8651a562fd6ffc9b6-%E8%AE%B0%E5%BD%95.png)

