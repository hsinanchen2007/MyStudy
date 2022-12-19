### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/b7ff8e18a405c21f493feb8b7d2c38dabb3253b64fceadc01ff807c22cf47468-image.png)
原地相除，看最终结果是否为1
### 代码

```c
bool isUgly(int num){
    if(num == 0) {
        return false;
    }
    while(num % 2 == 0) {
        num /= 2;
    }
    while(num % 3 == 0) {
        num /= 3;
    }
    while(num % 5 == 0) {
        num /= 5;
    }
    return num == 1 ? true: false;
}
```