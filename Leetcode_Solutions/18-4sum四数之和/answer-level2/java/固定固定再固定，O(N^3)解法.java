    其实说来跟三数之和是差不多的解法（暂时想到的是这个），简单地说就是一共分为三层。首先排序，排序完成后:
        最外层是一个遍历，在数组中依次固定数字；然后来到第二层，在最外层的基础上遍历除最外层已经固定的数字之外的数字（数组中往右数）；最后是第三层，此时我们已经固定了两个数字了，最后就是用三数之和中的双指针进行值的确定。
    解法比较简单，以后有时间再看看有没有骚操作。
    对了，代码附上：
```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        int start = 0;
        while(start<nums.length){
            if(start - 1 >= 0 && nums[start] == nums[start-1]){
                start++;
                continue;
            }
            int start_2 = start + 1;
            while(start_2<nums.length){
                if(start_2 - 1 >= start+1 && nums[start_2] == nums[start_2-1]){
                    start_2++;
                    continue;
                }
                int head = start_2 + 1;
                int tail = nums.length - 1;
                while(head<tail){
                    if(nums[start]+nums[start_2]+nums[head]+nums[tail] == target){
                        List<Integer> l = new ArrayList<Integer>();
                        l.add(nums[start]);
                        l.add(nums[start_2]);
                        l.add(nums[head]);
                        l.add(nums[tail]);
                        if(!result.contains(l)){
                            result.add(l);   
                        }
                        head++;
                    }else if(nums[start]+nums[start_2]+nums[head]+nums[tail] < target){
                        head++;
                    }else{
                        tail--;
                    }
                }
                start_2++;
            }
            
            start++;
        }
        return result;
    }
}
```
