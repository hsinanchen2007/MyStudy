### 解题思路
学习一位大佬的写法的c语言版本
自己在编译器里测试没问题
进leetcode测试一直报错AddressSanitizer: stack-buffer-overflow on address...
检查是 char s[] = ""; 没写大小
但是不写大小的话VC可以通过欸。

### 代码

```c
char *intToRoman(int num)
{
	char* map[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}};
	char s[100] = "";
    char *str = s;
	strcpy (s,map[3][num/1000]);
    strcat (s,map[2][num/100%10]);
    strcat (s,map[1][num/10%10]);
    strcat (s,map[0][num%10]);
	return str;
}
```