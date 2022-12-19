### 解题思路
此处撰写解题思路
我的思路:
    题目都说是返回的任意数，只要和为0就行，我们直接放1到n-1个数之间的数字直接放入到数组中，
最后一个位置就是前面所有数之后的负数（1，2，3，-6）等于0
### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int a[]=new int[n];
            int sum=0;
        for(int i=0;i<n-1;i++){
            a[i]=i;
            sum+=a[i];
        }
        a[n-1]=-sum;
        return a;
    }
}
```