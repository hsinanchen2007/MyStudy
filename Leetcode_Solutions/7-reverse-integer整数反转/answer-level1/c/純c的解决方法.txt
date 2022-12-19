### 解题思路
因为限制了只能是int类型，所以，就没有用long去做中间值对比，把最大值，最小值拆开进行对比，都是普通的思路，没有什么技术含量可言。

### 代码

int reverse(int x){
    int num = 0;
    while (x != 0) {
        if (num > 214748364 || (num == 214748364 && x%10 > 7)) {
            return 0;
        }
        if (num < -214748364 || (num == -214748364 && x%10 < -8)) {
            return 0;
        }
        num = x % 10 + num * 10;
        x = x / 10;
    }
    return num;
}
```