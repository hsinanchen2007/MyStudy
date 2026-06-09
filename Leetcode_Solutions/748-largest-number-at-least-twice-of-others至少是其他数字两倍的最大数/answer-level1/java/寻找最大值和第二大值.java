```java
        int max = 0;
        int maxIndex = 0;
        int oldMax = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max) {
                oldMax = max;
                max = nums[i];
                maxIndex = i;
            }else if(nums[i] > oldMax){
                oldMax = nums[i];
            }



        }
        if (oldMax == 0 || max / oldMax >= 2) {
            return maxIndex;
        }


        return -1;
```


核心思想是寻找最大值和第二大值，如果最大值是第二大值的两倍以上，那么即最大值索引。（代码有可优化之处，比如除以，判断，等等，请勿挑刺）