### 解题思路
此处撰写解题思路
· 对于小于2的整数num，返回1-num，或!num；
· 对于大于2的整数num，返回2*(num/2的补数) + (num % 2的补数)；

### 代码

```c
int findComplement(int num){
    if(num < 2){
        return !num;
    }else{
        return findComplement(num / 2) * 2 + !(num % 2);
    }
}
```