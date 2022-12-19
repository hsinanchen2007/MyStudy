# 方法一 哈希表解题
- 建立哈希表并且计数
- 找出计数为1的key
- 时间复杂度O(n),空间复杂度O(n)
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $count = count($nums);
        $hash = [];
        # 建立哈希表
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$nums[$i]])) {
                $hash[$nums[$i]] = 1;
            } else {
                $hash[$nums[$i]] += 1;
            }
        }
        # 找出计数为1的key
        foreach ($hash as $key=>$value) {
            if ($value==1) {
                return $key;
            }
        }
    }
}
```

# 方法二 异或运算
- PHP异或运算符为`^`
- 相同的值进行异或运算会变为0,0与任何值进行异或运算都为该值本身
- 时间复杂度O(n),空间复杂度O(1)
```PHP []
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $count = count($nums);
        $a = 0;
        # 异或运算
        for ($i=0;$i<$count;$i++) {
            $a ^= $nums[$i];
        }
        return $a;
    }
}
```
```GO []
func singleNumber(nums []int) int {
    a := 0
    for _,v := range nums{
        a ^= v
    }
    return a
}
```
