### 解题思路
此处撰写解题思路


### 代码

```java
class Solution {
    public int sumNums(int n) {
        double res=Math.pow(n, 2);
		res+=n;
		return (int)res>>1;
    }
}
```