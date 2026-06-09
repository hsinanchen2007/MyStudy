### 解题思路
奇数累加2，偶数累加1

### 代码

```c
int numberOfSteps (int num){
    return num>1?1+(num%2)+numberOfSteps(num>>1):num;
}
```