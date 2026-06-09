```java
//v1.0 抖个机灵
class Solution {
    public int sum(int...a){
        return Arrays.stream(a).sum();
    }
    public int add(int a, int b) {
        return sum(a,b);
    }
}
```
