### 解题思路
![图片.png](https://pic.leetcode-cn.com/7282fe704b0543a39869dccf64a1ed24aa39c8005c2e967d47a525f07f6a201a-%E5%9B%BE%E7%89%87.png)

第一个代码是之前写的，第二个代码是优化后的。
斐波那契数列就是前两项和等于第三项，f(1)+f(2)=f(3)
推广到N可迅速解决战斗

### 代码

```c
int climbStairs(int n){
    if(n==0){return 0;}
	if(n==1){return 1;}
    if(n==2){return 2;}
	int a=1;int b=2;int c=0;
	n=n-2;
	while(n--){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
```
改进法
```c
int climbStairs(int n){
    int a=0,b=1;int c=1;
    while(n--){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
```