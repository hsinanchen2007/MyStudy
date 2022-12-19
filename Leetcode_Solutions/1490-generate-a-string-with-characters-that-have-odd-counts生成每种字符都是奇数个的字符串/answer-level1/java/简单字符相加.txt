### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3b1b54a7e9df346650873209b13575b16bba0796e8334897355b23ad035e7bf8-image.png)

### 代码

```java
class Solution {
    public String generateTheString(int n)
    {
        String gene="";
        if(n%2 == 0)
        {
            for(int i =0; i < n-1; i++)
                gene+='a';
            gene+='b';
        }
        if(n%2!=0)
        {
            for(int i =0; i < n; i++)
                gene+='a';
        }
        return gene;
    }
}
```