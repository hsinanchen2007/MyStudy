# 分析题目
**给定一个整数n（1 ≤ n ≤ 30）,输出这个整数的报数序列,报数序列为对上一个报数序列的描述,默认整数1的报数序列为 1**
# 思路
**1.两层循环解决问题**
**2.因为给定的整数n和报数序列没有关联,所以要从1开始循环,直到和给定的整数n相等,才返回对应的报数序列,这是第一层循环**
**3.在第一层的循环中,每次循环要对上一个报数序列进行描述(1 被读作  "one 1"  ("一个一") , 即 11),所以要对上一个报数序列进行循环判断,这是第二层循环**
**4.在第二层循环中,利用数组进行判断,如果当前数字和数组中最后一位元素不同,则进行描述并清空数组,反之把当前数字推进数组中**
# 代码
```
function countAndSay($n) {
    $bw_str = '';
    for ($i = 1; $i <= $n;$i++) {
        if ($i == 1) {//默认$n 为1的时候 报数序列为 1
            $bw_str = '1';
        } else {
            $new_bw_arr = [];
            $new_bw_str = '';
            for ($j = 0; $j <= strlen($bw_str);$j++) {
                if (empty($new_bw_arr)) {
                    array_push($new_bw_arr, $bw_str[$j]);
                } else {
                    //判断当前数字是否和上一个数字相同
                    if (isset($bw_str[$j]) && $bw_str[$j] == end($new_bw_arr)) {
                        array_push($new_bw_arr, $bw_str[$j]);
                    } else {
                        if ($j !== strlen($bw_str)) {
                            $j--;
                        }
                        //对数组中的元素进行 读操作(1 被读作  "one 1"  ("一个一") , 即 11)
                        $new_bw_str .= count($new_bw_arr).$new_bw_arr[0];
                        $new_bw_arr = [];
                    }
                }
            }
            $bw_str = $new_bw_str;
        }

        if ($n == $i) {
            return $bw_str;
        }
    }
}
```
