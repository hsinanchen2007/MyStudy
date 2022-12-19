### 解题思路


![Screenshot 2020-03-16 at 11.22.14 PM.png](https://pic.leetcode-cn.com/a0cb2e36d8c0599e78cceb48e77adae308cbaaf8051ad6d68dd15c1dc38fc8db-Screenshot%202020-03-16%20at%2011.22.14%20PM.png)


### 代码

```c
// 判断是否为质数
bool isPrime(int num){
    if (num < 2) return false;
    int i;
    for(i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 算出含有1的个数m，m是否为素数
int countPrimeSetBits(int L, int R){
    int i,num,count = 0;
    for (i = L; i <= R; i++) {
        num = getOneCount(i);
        if (isPrime(num)) count++;
    }
    return count;
}

int getOneCount(int num){
    int count = 0;
    while (num != 0) {
        num &= (num - 1);
        count++;
    }
    return count;
}


```