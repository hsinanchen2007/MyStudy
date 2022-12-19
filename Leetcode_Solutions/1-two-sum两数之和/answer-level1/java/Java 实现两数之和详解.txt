# 在本题，解题的关键点在用于target与nums数组元素的差值，有两种解法：
1. 第一种：用双重循环来实现：
    ->优点：思维简单
    ->缺点：时间复杂度太高
    代码如下：
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for(int i = 0;i < nums.length;i++){
            int temp = target - nums[i];
            for(int j = i+1;j < nums.length;j++){
                if(temp == nums[j]){
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return  result;
    }
2. 第二种：用HashMap的来实现：
    ->优点：运用hashMap的特点key的唯一性，和集合的查找性
    ->缺点：需要对hashMap有一定的理解，最好能够理解hashMap的底层实现原理
    代码如下:
    public int[] twoSum(int[] nums, int target) {
        //返回的结果集
        int[] result = new int[2];
        //定义hashMap
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        //遍历集合
        for(int i = 0;i < nums.length;i++){
            //判断集合是否有nums[i]的值
            if(map.containsKey(nums[i])){
                //有，将各自的下表封装到result数组中
                result[0] = map.get(nums[i]);
                result[1] = i;
            }
            //没有,装入map集合中
            map.put(target-nums[i],i);
        }
        return  result;
    }