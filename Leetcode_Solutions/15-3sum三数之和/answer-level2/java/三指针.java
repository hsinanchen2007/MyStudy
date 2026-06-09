实际上是一个指针遍历，另外两个指针做左右边界，不断向中间移动。
整体代码如下：
```
        //思路
        //1st 排序（从左到右升序）
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        //2nd 遍历排序之后的数组，角标k，注意边界问题
        for(int k = 0;k< nums.length-2;k++){
            //2nd a）因为已经排序，如果当前值大于0，则和一定大于0
            if(nums[k] > 0) {
                break;
            }
            //2nd b) 当前这个值和前一个值重复时，跳过，因为在前一个值时，已经处理,无需重复重复处理
            if(k>0 && nums[k] == nums[k-1]) {
                continue;
            }
            //2nd c) 再开两个指针（初始值，i:k的右边一个;j:数组末尾的最后一个）来进行左右夹逼
            int i = k+1;int j = nums.length-1;
            while (i<j){
                int temp = nums[k]+nums[i]+nums[j];
                //2nd c) 1,当和大于0时，需要将j减少并跳过重复元素
                if(temp > 0){
                    --j;
                }
                //2nd c) 2,当和小于0时，需要将i增加并跳过重复元素
                else if(temp < 0){
                    ++i;
                }
                //2nd c) 3,当和等于0时，放入目标结果，并跳过重复元素
                else{
                    List<Integer> integers = Arrays.asList(nums[k], nums[i], nums[j]);
                    result.add(integers);
                    while (i<j && nums[j] == nums[--j]);
                    while (i<j && nums[i] == nums[++i]);
                }
            }
        }


        return  result;
```
