#### 一步到位:直接把二进制的每一位安排到最终位置上; 时间复杂度O(1), 空间复杂度O(1)
```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for(int i=0; i<32; i++){
            //每次都处理二进制的最低位, 这样方便进行&操作
            int cur = n&1;
            //直接把二进制的最低位安排到最终位置上, 不过怎么安排左移和右移???? 我是个蠢蛋, 只需要左移, 不需要右移!! 
            res = res + (cur<<(31-i));
            //update
            n = n>>1;
        }
        return res;
    }
}
```