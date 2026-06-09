```
    //利用数组下标，作为隐含的key，对应的数值作为value

    public List<Integer> findDisappearedNumbers(int[] nums) {

        //flags 用来作为指示器
        int[] flags = new int[nums.length];

        // 一开始 flags中数字均为-1
        for(int i = 0; i<flags.length; i++) flags[i] = -1;

        for(int i = 0; i<nums.length; i++){
            //nums[i] 是数组中的值
            // nums[i] 总是大于等于1， 小于等于数组长度的，所以它减一 就会是数组的下标
            // 如果这个数出现过，就记为0
            flags[nums[i] - 1] = 0;
        }

        List<Integer> ans = new ArrayList();

        for(int i = 0; i<nums.length; i++){
            if(flags[i] != 0){ //如果不为零，说明就没出现过
                ans.add(i+1); // 下标要加一才为其数字 
            }
        }
        return ans;
    }


```
