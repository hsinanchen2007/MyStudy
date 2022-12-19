
![WechatIMG38.jpeg](https://pic.leetcode-cn.com/dca64d9a42dd536d08086eb51f07013e58a4eb53691f70316b2f9ba984c94c01-WechatIMG38.jpeg)
```
代码块
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        // 排除掉上下的区间
        if(rec1[3] <= rec2[1] || rec1[1] >= rec2[3]) {
            return false;
        }
        // 排除掉左右的区间
        if(rec1[2] <= rec2[0] || rec1[0] >= rec2[2]) {
            return false;
        }

        // 剩下的必有交集
        return true;
    }
}

```
