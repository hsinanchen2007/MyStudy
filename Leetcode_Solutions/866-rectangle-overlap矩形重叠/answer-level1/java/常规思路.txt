### 解题思路
不重合的条件：**靠右的矩形的左下角 在靠左矩形右上角  的  右（上）方**。
![WechatIMG3.png](https://pic.leetcode-cn.com/d3042e96eb82da214ef47148ced18f2a7beccef11d8a1ff5bd3e5b5002ebf06e-WechatIMG3.png)
上图，不重合的条件：a>=x 或  b>=y
额，如有误，还请轻喷，难得做出来一题嘛

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        //假设rec2是靠左下的那个矩形
        if(rec1[0]>= rec2[2] || rec1[1]>=rec2[3]){
            return false;
        }
        //运气不好，那rec1肯定上靠左下的那个
        if(rec2[0]>= rec1[2] || rec2[1]>=rec1[3]){
            return false;
        }
        //卧槽，你俩有奸情
        return true;
    }
}
```