## **思路：**
- [1]哈希计数法：循环计数
    - 用一个数组$arr来保存每个数的出现个数  键（每个数） => 值(出现次数)
    - 然后循环找出来次数为1的 键
    - 然后返回键，就是只出现一次的数；
- [2]数组去重法
    - 额外数组$arr来保存
    - 遍历当前数组中每一个元素；
    - 如果某个元素是新出现的加入到$arr中；
    - 如果某个元素已经在$arr，那么就删除；
    - 最后留在$arr数组中的值就是只有一个的。
- [3]异或法
    - 看啦官网题解
    - 如果我们对 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位；
        `a XOR 0 = a`
    - 如果我们对相同的二进制位做 XOR 运算，返回的结果是 0；
        `a XOR a = 0`
    - XOR 满足交换律和结合律;
    - 所以我们只需要将所有的数进行 XOR 操作，得到那个唯一的数字。
## **code**
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
     //执行用时 :24 ms, 在所有 php 提交中击败了97.55%的用户
     //内存消耗 :17.3 MB, 在所有 php 提交中击败了66.24%的用户
     //哈希法  对每个元素进行计数
    function singleNumber($nums) {
        $arr = [];
        foreach ($nums as $value) {
            if(!isset($arr[$value])) {//防止Notice 数组键名未定义
                $arr[$value] = 1;//第一次出现
            }else{
                $arr[$value]++;//后续再次出现
            }
        }
        foreach ($arr as $key => $value) {
            if($value === 1) {//找到只出现一次的值
                return $key;
            }
        }
        return 0;
    }

    //执行用时 :24 ms, 在所有 php 提交中击败了97.55%的用户
    //内存消耗 :17.4 MB, 在所有 php 提交中击败了26.75%的用户
    //数组去重法：和第一种其实差别不是特别大，只不过这最后数组就只剩一个值。
    function singleNumber2($nums) {
        $arr = [];
        foreach ($nums as $value) {
            if(!isset($arr[$value])) {
                $arr[$value] = 1;//第一次出现就1
            }else{
                unset($arr[$value]);//第二次出现就删除
            }
        }
        //下面这个循环为了取出来 数组中最后的一个元素，感觉怪异
        foreach ($arr as $key => $value) {
            return $key;
        }
    }

    //异或法
    //执行用时 :32 ms, 在所有 php 提交中击败了70.95%的用户
    // 内存消耗 :17.5 MB, 在所有 php 提交中击败了8.92%的用户
    function singleNumber3($nums) {
        $re = 0;
        foreach ($nums as $value) {
            $re ^= $value;//进行异或运算
        }
        return $re;
    }

}



$obj  = new Solution();
$nums = [4,1,2,1,2];
$re   = $obj->singleNumber1($nums);
var_dump($re);

```
