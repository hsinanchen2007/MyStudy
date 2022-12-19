
参考与修改：
[吴彦祖 - 位掩码](https://leetcode-cn.com/problems/subsets/solution/hui-su-die-dai-wei-yan-ma-qing-xi-si-lu-zhu-xing-f/)
对于[1,2,3]，可用三位二进制表示是否选择对应下标的数组元素。则有8种组合方式。二进制表达
![Screen Shot 2019-11-20 at 9.58.09 PM.png](https://pic.leetcode-cn.com/bc05bf8b7754be5db5544382b90780395265a9e83f3b32e95e25cfdf76a2c4ed-Screen%20Shot%202019-11-20%20at%209.58.09%20PM.png)
初始化数组长度n，最终结果的长度res_len=1<<n，此处位运算表示的是2^n。
对于每种结果，对于i在遍历区间[0,res_len)[0,res_len)中:
其实这时，我们已经得到8种子集的二进制表达情况。
初始化中间结果sub=[]
从数组第一位到最后一位进行遍历，对于j在遍历区间[0,n)[0,n)中：
若满足条件i & (1 << j)，表示每一位是否为， 第j位是否有1，若满足，则将该位元素加入中间结果sub中
将sub加入res
返回res

```
function subsets($nums) {
    $count = count($nums);
    $max = 1 << $count;
    $res = [];   
    for($i = 0; $i < $max; $i++){
        $sub = [];
        for($j = 0; $j < $count; $j++){
            if($i & (1 << $j)){
                $sub[] = $nums[$j];
            }
        }
        $res[] = $sub;
    }
    return $res;
}
```
