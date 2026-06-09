# **方法一：哈希表**
思路：遍历哈希表一遍，检查表内是否存在元素，若已存在就销毁，不存在就添加进去，最后只剩出现一次的元素在表内。

    function singleNumber($nums) {
        $hash = [];
        for($i = 0; $i < count($nums); $i++){
            if(!isset($hash[$nums[$i]])){
                $hash[$nums[$i]] = $nums[$i];
            }else{
                unset($hash[$nums[$i]]);
            }
        }
        return key($hash);
    }

**哈希表改进版**
思路：利用自带函数得出元素为键，出现次数为值。然后遍历一次选择出现次数是一次的键。

    function singleNumber($nums) {
        $arr = array_count_values($nums);
        foreach ($arr as $key => $value) {
            if ($value === 1) {
                return $key;
            }
        };

    }

# **方法二：排序**
思路：利用自带函数得出元素为键，出现次数为值；然后按值进行排序，然后输出第一个键。

    function singleNumber($nums) {
        $arr = array_count_values($nums);
        asort($arr);
        return key($arr);
    }

# **方法三：位运算**
思路：相同的数相异或都得到0，任何数跟0异或都得到原本那个数

    function singleNumber($nums) {
        for ($i=0, $a = 0;$i<count($nums);$i++) {
            $a ^= $nums[$i];
        }
        return $a;

    }