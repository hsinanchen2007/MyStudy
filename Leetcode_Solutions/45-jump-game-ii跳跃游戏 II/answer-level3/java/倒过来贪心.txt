```
public int jump(int[] nums) {
        int res = 0;
        int cur = nums.length -1;

        while (cur > 0){
            for (int i = 0 ; i < cur ; i++){
                if (nums[i] + i >= cur){
                    cur = i;
                    res++;
                    break;
                }
            }
        }

        return res;
    }
```
从后向前 每次都尽量远一点
就是有点慢
