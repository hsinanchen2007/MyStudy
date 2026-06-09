### 解题思路
1.判断符号用flag记录，将所给x取绝对值，同时考虑特殊情况-2147483648,即二进制表示为1后面31个0
2.每次将倒转数（倒转数表示为long long，这样判断溢出时就不会溢出）乘10再加上x余10，同时每次都进行移除判断，溢出则返回0
3.最后加上符号返回

### 代码

```c
int reverse(int x){
  int flag=0;
  if(x<0) flag=1;
  if(x==-2147483648) return 0;
  x=abs(x);
  long long a=0;
  while(x!=0){
      if(a*10>2147483647) return 0;
      a*=10;
      if(a+x%10>2147483647) return 0;
      a+=x%10;
      x/=10;
  } 
  if(flag)
  return -a;
  else return a;
}
```