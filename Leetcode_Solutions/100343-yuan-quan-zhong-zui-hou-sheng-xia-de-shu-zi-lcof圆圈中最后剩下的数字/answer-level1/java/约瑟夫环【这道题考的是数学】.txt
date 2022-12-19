![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/7052fa4568fc4a5aad31abf89deea63effa0ffb6fbd56a746c9731bbb59bf4ec-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    //有一个递推公式
    //f(n,m) = [f(n-1,m)+m]%n 
    public int lastRemaining(int n, int m) {
        if(n == 1) return 0;
        return (lastRemaining(n-1,m)+m)%n;
    }
}
```