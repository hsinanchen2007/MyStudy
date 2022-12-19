### 解题思路
此处撰写解题思路
判断该数字的正负，为负时直接返回false；
为正时将数字存入数组中，让两个指针分别从数组头和尾向中间移动，出现不同的数字时，直接返回false。
### 代码

```c
bool isPalindrome(int x){
    if(x<0)
        return 0;
    int a[10],i=0,j=0;
	for(;x;a[i]=x%10,i++,x=x/10);
	for(i--;j<=i;j++,i--){
		if(a[j]!=a[i])
			return 0;
	}
	return 1;
}

```