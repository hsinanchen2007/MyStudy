class Solution {

    /**
     * @param Integer[] $arr
     * @return Boolean
     */
    function uniqueOccurrences($arr) {
        // 判断数组元素出现的个数
        $count = array_count_values($arr);
        // 再次判断数组元素出现的个数
        $count = array_count_values($count);
        // 如果都是独一无二的,则数组长度等于数组元素的和
        if(count($count) == array_sum($count)){
            return true;
        }else{
            return false;
        }
    }
}

![微信图片_20191009102554.png](https://pic.leetcode-cn.com/3296c0247c01aabab7e2554564893505685b86670170463df8dd317f0e031c95-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191009102554.png)
