
//二次for循环，二个指针都从索引值0开始，当两个指针索引值相同时，则跳过
public static int singleNumber(int[] nums) {
    for(int i =0;i<nums.length;i++) {
        //打标，每一次i移动时，将该标识设置为true
        boolean b = true;
        for(int j = 0;j<nums.length;j++) {
            //当两个指针索引值相同时，则跳过
            if(i==j){
                continue;
            }
            // 当出现相同元素时，当前循环停止
            if(nums[i]==nums[j]){
                b = false;
                break;
            }
        }
        // b 没有改变成false时，说明当前元素在数组中没有重复，只出现了一次
        if(b){
            return nums[i];
        }
    }
    return 0;
}