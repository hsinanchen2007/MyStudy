class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $count = count($nums);//定义数组的个数，最好定义，因为是原地删除，所以如果下面使用了count函数的话，在循环时会一直改变count函数的值。所以不能用
        if($count <= 1){
            return $count;//如果只有一个或空数组，就直接返回
        }
        $num = $nums[0];//定义一个变量，是它等于数组的开头
        for($i = 1;$i < $count;$i++){
            if($nums[$i] == $num){
                unset($nums[$i]);//如果数组等于变量，即有重复项，就原地删除该数组值
            }else{
                $num = $nums[$i];//如果数组不等于变量，就将该数组值赋值给变量，使其可以判断下一个数组值
            }
        }
        return count($nums);//返回该数组长度
    }
}