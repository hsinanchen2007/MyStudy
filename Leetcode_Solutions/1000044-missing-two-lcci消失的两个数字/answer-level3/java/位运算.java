和之前的一道位运算其实是一样的

```
public int[] missingTwo(int[] nums) {
        int xor = 0;
        for(int n : nums) {
            xor ^= n;
        }
        int len = nums.length;
        for(int i = 1; i <= (len + 2); i++) {
            xor ^= i;
        }
        
        int a = 0;
        int b = 0;
        int mask = 1;
        for(int i = 0; i < 32; i++) {
            mask = 1 << i;
            if ((mask & xor) != 0) {
                break;
            }
        }
        
        for(int n : nums) {
            if ((n & mask) == 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        for(int n = 1; n <= (len + 2); n++) {
            if ((n & mask) == 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        
        
        int[] res = new int[2];
        res[0] = a;
        res[1] = b;
        return res;
    }
```
