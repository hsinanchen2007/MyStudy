### 解题思路
将数字拆开存入数组然后i遍历，将第一个6换成9即可，这里可以用加3000，300，30，3来实现。
### 代码

```c
int nums[15];

int maximum69Number (int num){
    int len = 0, tmp = num;
    while(tmp > 0){
        len++;
        nums[len] = tmp%10;
        tmp /= 10;
    }
    int i;
    for(i = len; i >= 1; i--){
        if(nums[i] > 5 && nums[i] < 9) break;
    }
    return num + 3*(int)pow(10, (double)(i-1));
}


```