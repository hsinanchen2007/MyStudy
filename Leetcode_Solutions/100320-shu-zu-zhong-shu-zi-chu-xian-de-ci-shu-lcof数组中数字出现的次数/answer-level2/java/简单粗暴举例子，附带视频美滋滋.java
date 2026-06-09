### 解题思路
看那么多字不如举个栗子吧，这个肯定能看懂。
![leecode.mp4](4cf6a5ca-ff2a-4c9d-8bdb-6d854d6f9ade)

### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        int xor = 0;

        for(int i:nums){
            xor ^= i;
        }

        int s = 1;
        while((xor & s) == 0){
            s <<= 1;
        }
        int[] res = new int[2];
        for(int i:nums){
            if((i&s) == 0){
                res[0] ^= i;
            }else{
                res[1] ^= i;
            }
        }
        return res;
    }
}
```