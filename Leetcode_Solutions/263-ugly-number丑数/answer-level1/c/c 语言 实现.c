### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/4d8fce2653eba82352f0a9a28143f5a14b05439227fb9f040eb0a86881e2996f-image.png)

### 代码

```c
bool isUgly(int num){
    if(0 == num)
    {
        return false;
    }

    while(num % 2 == 0)
    {
        num /= 2;
    }

    while(num % 3 == 0)
    {
        num /= 3;
    }

    while(num % 5 == 0)
    {
        num /= 5;
    }

    return num == 1;
}
```