- 时间复杂度O(n)
- 空间复杂度O(1)
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        $count = count($nums);// 求合
        $last = 0;// 重塑数组的索引,可以理解为这个索引存储不为零的值
        for ($i=0;$i<$count;$i++) {
            if ($nums[$i] != 0) {
                # 碰到不为零的数,将该数放在索引位置
                $nums[$last] = $nums[$i];
                # 索引递增,为了方便理解这样写.也可以去掉$last++这行并将$nums[$last]改成$nums[$last++]
                $last++;
            }
        }
        # 索引位置往后补零,为什么不是$i=$last+1,因为上面在操作最后一个不为零的值时默认将索引递增了
        for ($i=$last;$i<$count;$i++) {
            $nums[$i] = 0;
        }
    }
}
```
