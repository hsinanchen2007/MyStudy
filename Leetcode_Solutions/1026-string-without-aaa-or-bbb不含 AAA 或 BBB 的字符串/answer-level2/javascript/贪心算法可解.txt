题目可以分3种情况进行讨论

- A = B时
- A > B时
- A < B时

当A=B时，此时最简单，我们只需要每次写入一个a和一个b来回交替即可。

当A > B或者A < B时，我们要尽量将AB的关系转化为A=B，由题目条件可知，当A>B时，我们应该写入aab字符串，这样A在某一时刻会和B的数目相等。解法就可以转化为A=B，同理当A<B时，我们应该写入bba字符串，直到A=B或者AB被消耗完。

可以将解题过程想象成两个选手赛跑100米，跑的慢的选手初始位置在50米处，跑的快的选手初始位置在20米处，跑得快的选手在追上跑得慢的选手后两者一起以同样的速度跑过终点

JS的解法：

```
var strWithout3a3b = function(A, B) {
    let res = "";
    while (A > 0 || B > 0) {
        if (A > B) {
            if (A > 1) {
                res += "aa"
                A -= 2;
            } else {
                res += "a";
                A--;
            }
            if (B > 0) {
                res += "b";
                B--;
            }
        } else if (A<B) {
            if (B > 1) {
                res += "bb"
                B -= 2;
            } else {
                res += "b";
                B--;
            }
            if (A > 0) {
                res += "a";
                A--;
            }
        } else {
            res += "ab";
            A--;
            B--;
        }
    }
    
    return res;
};
```

时间复杂度：O(A+B)。
