### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trailingZeroes(int n) {
        int cnt=0;
        while(n>=5){
            cnt+=n/5;
            n/=5;
        }
        return cnt;
    }
}
```