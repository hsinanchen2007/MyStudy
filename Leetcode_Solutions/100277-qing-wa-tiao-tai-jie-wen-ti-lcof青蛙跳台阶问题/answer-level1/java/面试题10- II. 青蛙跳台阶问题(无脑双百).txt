### 解题思路
注意当n=0的时候是1种跳法

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n<2)return 1;
        int fb1=1;
        int fb2=1;
        int item=0;
        for(int i=2;i<=n;i++){
            item=(fb1+fb2)%1000000007;
            fb2=fb1;
            fb1=item;
        }
        return item;
    }
}
```