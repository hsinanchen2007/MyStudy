```
//每次遍历当前元素时，检查其后的元素是否与当前元素相同，如果相同则进行移位。
public static int delRepeatElement(int [] nums) {
        int delCount = 0;//删除重复元素个数计数
        for(int i = 0; i < nums.length -delCount-1; i++) {
            //在 i+1 不能大于等于 数组长度的条件下，判断当前索引下元素与下一个元素是否重复
            if(i < nums.length-1 && nums[i] == nums[i+1]) {
                int k = 0;
                // 如果下一个元素与后面的元素还有相同，那么把相同元素忽略，找到最后一个不同的元素开始进行移位操作
                for(int j = i+1; j < nums.length-delCount-1; j++) {
                    //忽略i 索引后的与i索引处的元素相同的元素
                    if(nums[j] == nums[j+1]){
                        k ++;
                        continue;
                    }
                    // 把之后开始不同的元素进行移位操作
                    nums[j-k] = nums[j+1];
                }
                delCount = delCount + k +1;
            }
        }
        return nums.length - delCount ;
    }
```

