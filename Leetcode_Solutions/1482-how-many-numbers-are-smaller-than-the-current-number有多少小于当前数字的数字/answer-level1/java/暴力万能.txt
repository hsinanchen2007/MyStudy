```
public int[] smallerNumbersThanCurrent(int[] nums) {
            int[] res = new int[nums.length];
            for (int i = 0 ; i < nums.length; i ++){
                int num = 0;
                for (int j = 0 ; j < nums.length; j ++){
                    if (i == j ) continue;
                    if(nums[i] > nums[j]) num ++;
                }
                res[i] = num;
            }
            return res;
        }
```
