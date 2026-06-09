### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
int x = 0;
for(int i=2;i<=n;i++){
x= (m+x)%i;
}
return x;
    }
}
```套用公式，还是没看懂