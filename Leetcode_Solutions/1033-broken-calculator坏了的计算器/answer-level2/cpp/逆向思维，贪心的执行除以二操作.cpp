### 解题思路
此处撰写解题思路
leetcode官方题解的评论很有价值，即正向思维需要贪心的执行+1操作，而逆向则是贪心的执行/2操作，先大后小（先大幅度再小幅度变化）更容易都得到正确结果。
### 代码

```cpp
class Solution {
public:
       int brokenCalc(int X, int Y) {
        if(X==Y) return 0;
        if(Y%2==0) {
            if(X>Y) return X-Y;
            else return brokenCalc(X,Y/2)+1;
        }
        else {
            if(X>Y) return X-Y;
            else return brokenCalc(X,Y+1)+1;
        }
    }
};
```