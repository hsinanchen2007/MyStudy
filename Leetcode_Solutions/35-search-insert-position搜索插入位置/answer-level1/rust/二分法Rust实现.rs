- 分治到最后，判断最后的剩下数字与target的关系，决定插入位置
- 两次大小的比较，都没有取等，是因为测例要求相等时插入到左侧
- 注意用`as i32`做类型转换
- 有没有什么办法能不复制一次数组？（`let mut temp = nums;`），刚刚接触rust，很多东西不太懂

```
// 二分查找
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut temp = nums;
        let size = temp.len();
        if size == 1 {
            if temp[0] < target {
                return 1 as i32
            } else {
                return 0 as i32 // 大于等于都是要放在左边
            }
        }
        if temp[size/2] > target {
            temp.split_off(size/2);
            Self::search_insert(temp, target) as i32
        } else {
            (size/2) as i32 + Self::search_insert(temp.split_off(size/2),target)
        }
    }
}
```