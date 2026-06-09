### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maximum(int a, int b) {
        int [] num=new int[2];
        num[0]=a;
        num[1]=b;
        Arrays.sort(num);
        return num[1];
    }
}
```