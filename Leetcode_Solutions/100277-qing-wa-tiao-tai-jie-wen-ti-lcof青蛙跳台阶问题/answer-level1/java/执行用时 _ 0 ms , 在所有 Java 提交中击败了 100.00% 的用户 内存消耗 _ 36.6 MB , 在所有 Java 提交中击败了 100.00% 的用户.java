### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numWays(int n) {
        int one=0;
        int two=1;
        int tap=0;
        if(n==0){
            return 1;
        }
        for (int i=1;i<=n;i++){
            tap=(one+two)%1000000007;
            one=two;
            two=tap;
        }
        return tap;
    }
}
```