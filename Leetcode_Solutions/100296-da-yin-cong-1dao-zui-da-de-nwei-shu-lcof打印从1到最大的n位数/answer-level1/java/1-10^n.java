### 解题思路
此处撰写解题思路
时间复杂度：O(10^n)
空间复杂度：O(3)
### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int s=(int)Math.pow(10,n);
        int [] A=new int[s-1];
        for(int i=1;i<s;i++)
            A[i-1]=i;
        return A;
    }
}
```