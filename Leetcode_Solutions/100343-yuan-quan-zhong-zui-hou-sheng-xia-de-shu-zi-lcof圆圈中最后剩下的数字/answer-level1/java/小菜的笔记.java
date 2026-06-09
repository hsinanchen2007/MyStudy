### 解题思路
此处撰写解题思路
约瑟夫环的问题，函数返回的是当杀死一个小朋友时，最后剩下的小朋友的位置。
### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        if(n==2){
            if(m%2==0)return 0;
            else return 1;
        }
        return (lastRemaining(n-1,m)+m)%n;

    }
}
```