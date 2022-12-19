# **思路：**
- PHP的数组函数真的丰富；
    - array_count_values() 返回一个数组： 数组的键是 array (数组的值必须是字符或者数字 )里单元的值； 数组的值是 array 单元的值出现的次数
    - array_flip() 对数组进行键值互换
    - 因为只有一个数字是出现一次的，所以那么最后也就是数组的第2个单元 也就是数组下标为1的值；
    - array_search — 在数组中搜索给定的值，如果成功则返回首个相应的键名
    - array_keys — 返回数组中部分的或所有的键名
    - 
# **Code**
```
//////////////////////////////////【函数法】//////////////////////////////////////////
    //函数法
    //执行用时 :32 ms, 在所有 php 提交中击败了70.95%的用户
    //内存消耗 :17.5 MB, 在所有 php 提交中击败了18.79%的用户
    function singleNumber4($nums) {
        $nums = array_count_values($nums);//统计 各个单元出现的次数 返回的数组是 键=>出现的次数
        $nums = array_flip($nums);//互换键值
        return $nums[1];//由于出现的只有一次
    }

    //函数法
    //执行用时 :28 ms, 在所有 php 提交中击败了88.07%的用户
    //内存消耗 :17.1 MB, 在所有 php 提交中击败了93.95%的用户
    function singleNumber5($nums) {
       //计算数组元素出现个数
       $nums = array_count_values($nums);
       // php数组根据值为1的 获取键名
       $nums = array_keys($nums,1);
       return $nums[0];
    }

    //函数法
    function singleNumber6($nums) {
        //计算数组元素出现个数
        $nums = array_count_values($nums);
        // 在数组$nums中搜索给定的值1，如果成功则返回首个相应的键名
        return array_search(1,$nums);
    }
```


