### 解题思路
如题

先选出A，B中的较大值（这里是A>=B，否则交换A，B）。
计算出可以先排多少个1A1B，使得剩下的部分可以重复使用2A1B填充，
即 2*(B-x) <= A-x <= 2*(B-x)+2。
排列x个ab，之后不断排列aab直到结束。

如9A6B，x取3，结果就是 ababab aabaabaab
![TIM图片20191214201629.png](https://pic.leetcode-cn.com/2156df1bca6abf48d910c729df037c09d699a3ac9c26c38b8724f26ba4d78e3e-TIM%E5%9B%BE%E7%89%8720191214201629.png)


### 代码

```java
class Solution {
    public String strWithout3a3b(int A, int B) {
        StringBuilder ret = new StringBuilder(A+B);
        //使A>B，否则交换ab
        char ca = 'a';
        char cb = 'b';
        if(B > A) {
            int tmp = A;
            A = B;
            B = tmp;
            ca = 'b';
            cb = 'a';
        }
        int limit = B*2 - A; //最多可以加多少个ab
        if(limit < 0) {
            limit = 0;
        }
        //一A一B
        for(int i = 0;i < limit;i++) {
            ret.append(ca);
            ret.append(cb);
        }
        A -= limit;
        B -= limit;
        //两A一B
        while(A + B > 0) {
            if(A > 1) {
                ret.append(ca);
                ret.append(ca);
                A -= 2;
            } else if(A == 1) {
                ret.append(ca);
                A = 0;
            }
            if(B > 0) {
                ret.append(cb);
                B--;
            }
        }

        return ret.toString();
    }
}
```