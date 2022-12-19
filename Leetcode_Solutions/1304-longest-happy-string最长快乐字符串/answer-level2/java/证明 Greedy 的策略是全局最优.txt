### 解题思路
这道题靠直觉写出来不难，难的是证明贪心策略最后的结果是最优的解法之一。

可以从**缩小问题规模**作为思考和证明的切入口。

假设 a > b > c ，我们可以按照最基本的情况考虑，一个a + 一个b + 一个c : abc abc abc ...
因为 c 最少，b 次之，最后肯定会形成一个局面:

(一段) abc abc abc | (二段) ab ab ab | (三段) a a a a a


可以发现，想让组合的字符串最长，也就是让第三段里的 a 更多的被前面的一二段消化掉。也就是每一组 **abc** 和 **ab** 里都可以插入 a, 由于题目限制不能有连续三个相同字符，所以最后可以变成 (一段) aabaac | (二段) aab。

所以，在初始局面时（一段），我们去尽可能的放置数量最多的字符，同时保证它和前2个不一样，即没有aaa/bbb/ccc 的重复。在二段依旧如此，三段也是依旧。
这就证明了该贪心策略是可以得到全局最优解之一的。

### 代码

```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        String res = "";
        int[] A = new int[3];
        A[0] = a;
        A[1] = b;
        A[2] = c;
        int i;
        
        while(true) {
            int ban = -1;
            for(i = 0; i < A.length; i++) {
                if(res.length() >= 2 && res.charAt(0) == res.charAt(1) && res.charAt(0) - 'a' == i) {
                    ban = i;
                    break;
                }
            }
            
            int select = -1;
            for(i = 0; i < A.length; i++) {
                if(A[i] <= 0 || ban == i) {
                    continue;
                }
                if(select == -1 || A[i] > A[select]) {
                    select = i;
                }
            }
            if(select == -1) {
                break;
            }
            res = (char) (select + 'a') + res;
            A[select] -= 1;
        }
        
        return res;
    }
}
```