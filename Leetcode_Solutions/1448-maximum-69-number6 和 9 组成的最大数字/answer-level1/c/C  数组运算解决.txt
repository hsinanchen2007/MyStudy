### 解题思路
从低位到高位取出每一位的数字
然后从高位到低位依次还原，遇到第一个6把它变成9，flag控制6变9的数量，默认只变一次
ps：如果有从高到低取每一位的方法会更简单，但目前没有思路。
转字符串需要用到额外的库，或者手动实现，但消耗会更大。

### 代码

```c
int maximum69Number (int num){
    int num_list[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    for (; i < 11; i++){
        num_list[i] = num % 10;
        num /= 10;
    }
    int flag = 1, new_num = 0;
    for (i = 10; i >= 0; i--){
        if (flag && num_list[i] == 6){
            num_list[i] = 9;
            flag--;
        }
        new_num = 10 * new_num + num_list[i];
    }
    return new_num;
}
```