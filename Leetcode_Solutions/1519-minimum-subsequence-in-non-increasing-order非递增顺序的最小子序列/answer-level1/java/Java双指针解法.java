1.排序数组
2.指针指向首尾节点
3.遍历数组，后面元素和小于前面元素和就添加元素到队列里

public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int i = 0,j = nums.length - 1;
        List<Integer> result = new ArrayList ();
        result.add(nums[j]);
        int sum1 = nums[i];
        int sum2 = nums[j];
        while(i<j){
            while(i<j && sum1 <sum2){
                i++;
                sum1 = sum1 +nums[i];
            }
            while(i<j && sum1 >= sum2){
                j--;
                sum2 = sum2 +nums[j];
                result.add(nums[j]);
            }
        }
        return result;
}