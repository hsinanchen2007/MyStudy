
![image.png](https://pic.leetcode-cn.com/4bceca79984730aaf1c5583e99f4fbb40053a8b5927c177042d471ec20b6165c-image.png)
n=5，m=3
d位置是安全的
n=4的时候d位置的索引就是n=5的时候左移3位
所以要f(4)+3移回去，还要记得取余，得到f(5)=(f(4)+3)%5
后面的按照这个想法推回去就可以
看的是这个链接:)
https://www.bilibili.com/video/BV1c7411x7p9?from=search&seid=9076788247352072953

