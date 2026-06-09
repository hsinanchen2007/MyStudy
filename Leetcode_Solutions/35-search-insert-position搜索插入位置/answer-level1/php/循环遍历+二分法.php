# Thinking
[思考]
- 循环遍历
    - 一般这种都可以暴力出来
    - 循环数组，判断元素值 与 目标的元素大小关系
        - 如果相等直接返回下标索引；
        - 如果大于某个值，小于下个值，那就返回下一个值的下标索引；
- 二分法 【强推】
    - 题目告诉你“排序数组”，其实就是在疯狂暗示你用二分查找法！！！
    - 注意mid的求法  ($left+$right) >> 1;
    - 注意左右边界的判断，根据题意来

# Coding
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
     // 笨重- 虽然也是循环，但是稍有遗落就会错
     //执行用时 :16 ms, 在所有 php 提交中击败了67.88%的用户
     //内存消耗 :15.6 MB, 在所有 php 提交中击败了75.61%的用户
    function searchInsert($nums, $target) {
        $size = count($nums);
        if(!$size) {
            return 0;
        }
        for($i=0; $i<$size; $i++) {
            if($nums[$i] == $target) {
                return $i;//直接命中
            } elseif ($nums[$i] > $target) {
                return 0;//第一个值大于目标值
            } elseif (!isset($nums[$i+1])) {
                return $size;//最后一个值
            } elseif ($nums[$i] < $target && $nums[$i+1] > $target) {
                return $i + 1;
            }
        }
        return $size;
    }

    // 循环法
    //执行用时 : 16 ms, 在所有 php 提交中击败了67.19%的用户
    //内存消耗 : 15.5 MB, 在所有 php 提交中击败了76.83%的用户
    function searchInsert2($nums, $target) {
        foreach ($nums as $key => $value) {
            if($value == $target){// 如果刚好找到那么就 返回索引下标
                return $key;
            }elseif($value > $target){// 如果当前值要是大于的话，那么就插入前一个值
                return $key;
            }
        }
        return sizeof($nums);// 实在找不到，就返回最后位置
    }

    // 二分
    // 执行用时 :12 ms, 在所有 php 提交中击败了94.27%的用户
    // 内存消耗 :15.6 MB, 在所有 php 提交中击败了68.29%的用户
    function searchInsert3($nums, $target) {
        $size = sizeof($nums);
        if(!$size) return 0;
        $left = 0;
        $right= $size;// 有可能是插入最后
        while($left < $right) {
            $mid = ($left+$right) >> 1; // 无符号右移 1 位
            echo $mid,'-';
            if($target > $nums[$mid]) {
                $left = $mid + 1;// 因为肯定是要插入下一个位置
            }else{
                $right= $mid;// 再判断一下中间的值
            }
        }
        return $right;// 这里返回left或者right都行
    }
}

$obj    = new Solution();
$nums   = [1,3,4,5,9,10];
$target =  8;
$re     = $obj->searchInsert($nums,$target);
var_dump($re);
```
