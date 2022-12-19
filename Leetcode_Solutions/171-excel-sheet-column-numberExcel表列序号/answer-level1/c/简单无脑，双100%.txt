### 解题思路
![3019fe1cea7f27301ac8c765d6d2a01.png](https://pic.leetcode-cn.com/6bb5267e37fd5a1abe9d8bce68a3a9e5dd8442f00b51994ea4c29197a6995808-3019fe1cea7f27301ac8c765d6d2a01.png)
简单无脑

### 代码

```c
int titleToNumber(char * s){
int a=0;
int i=0;
int sum=0;
for(;s[i]!='\0';i++)
{
 a=s[i]-'A'+1;
sum=sum*26+a;
}
return sum;
}
```