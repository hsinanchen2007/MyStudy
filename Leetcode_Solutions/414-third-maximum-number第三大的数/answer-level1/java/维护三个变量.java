创建max,second和third变量来存放最大、第二大和第三大的值。
将second和third初始化为Integer.MAX_VALUE应该是没有问题吧？

```
public int thirdMax(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        int max = nums[len-1];
        int second = Integer.MAX_VALUE;
        int third = Integer.MAX_VALUE;
        while(len>0){
            if(nums[len-1]<max){
                second = nums[len-1];
                break;
            }
            len--;
        }
        while(len>0){
            if(second!=Integer.MAX_VALUE&&nums[len-1]<second){
                third = nums[len-1];
                break;
            }
            len--;
        }
        if(third !=Integer.MAX_VALUE){
            return third;
        }else{
            return max;
        }
    }
```

Accepted
26/26 cases passed (2 ms)
Your runtime beats 62.49 % of java submissions
Your memory usage beats 68.24 % of java submissions (38.1 MB)