### 解题思路
此处撰写解题思路

### 代码

```c
int addDigits(int num){
    if (num>=10)
      return addDigits(num/10+num%10);
    else
      return num;
}
```