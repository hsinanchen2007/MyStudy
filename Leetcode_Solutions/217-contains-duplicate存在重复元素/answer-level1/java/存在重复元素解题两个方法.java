方法一：利用二次for 循环查找对比：结果超时
```
public static boolean containsDuplicate(int[] nums) {
    for(int i =0;i<nums.length-1;i++) {
        for(int j = i+1;j<nums.length;j++) {
            if(nums[i]==nums[j]){
                return true;
            }
        }
    }
    return false;
}
```
代码优化：减少4倍的遍历次数，但结果仍然超时：
```
public static boolean containsDuplicate1(int[] nums) {
    for(int i = 0; i<nums.length/2; i++){
        if(i != nums.length-1-i && nums[i]==nums[nums.length-1-i]) {
            return true;
        }
        for(int j = i+1; j < nums.length/2;j++) {
            if( j != nums.length-1-j && nums[nums.length-1-j] == nums[j]){
                return true;
            }
            if(nums[i] == nums[j] || nums[nums.length-1-i] == nums[j]){
                System.out.println("i:"+i+",j:"+j);
                return true;
            }
            if(nums[i] == nums[nums.length-1-j] || nums[nums.length-1-i] == nums[nums.length-1-j]) {
                System.out.println("i:"+i+",j:"+j);
                return true;
            }
        }
    }
    return false;
}
```

方法二：利用Set 不重复性，将数组元素放入set集合中，结束后比较set 集合与 数组的长度，如果一致则没有重复，如果不一致，则重复
测试通过
```
 public static boolean containsDuplicate(int[] nums) {
    Set<Integer> set = new HashSet();
    for(int i:nums){
        set.add(i);
    }
    if(set.size() == nums.length){
        return false;
    }
    return true;
}
```


