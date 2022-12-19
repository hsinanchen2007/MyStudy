### 解题思路
此处撰写解题思路
这个题主要需要细心，开始没有判断x%10 == 0的情况后来，出现一个问题是int num越界的问题，后来在网上查
让使用double用上之后就可以提交通过了。
### 代码

```c
bool isPalindrome(int x) {
	double num = 0;
	int cu_x = x;
	if (x == 0)
    {
		return true;
    }
    if((x % 10) == 0 || x < 0) 
    {
        return false;
    }
	while (x > 0)
	{
		num = (num*10) + (x % 10);
		x = x / 10;
	}
	if (num == cu_x)
	{
		return true;
	}
	else
	{
		return false;
	}
}
```