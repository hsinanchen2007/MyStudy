### 解题思路
此处撰写解题思路
[https://blog.csdn.net/u011500062/article/details/72855826](https://blog.csdn.net/u011500062/article/details/72855826)
链接附上  写的很详细 就不具体介绍了
### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        int p = 0;//当n=1的时候 无论m为多少，下标都是0
        for(int i = 2;i<=n;i++){//将n等于1带入，进行逆推导。
            p = (p+m)%i;
        }
        return p;
    }
}
```