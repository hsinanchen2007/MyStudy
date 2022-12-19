```
public int majorityElement(int[] nums) {
        int count = 0;
        int res = 0;
        
        for(int n : nums) {
            if (count == 0) {
                count++;
                res = n;
            } else {
                if (n == res) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        
        if (count == 0) {
            return -1;
        }
        
        return res;
    }
```
