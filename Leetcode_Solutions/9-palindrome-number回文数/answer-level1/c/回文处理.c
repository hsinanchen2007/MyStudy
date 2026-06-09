### 解题思路
此处撰写解题思路
1、方案1：使用数组保存没位的值，回文判断，字符串回文也可以这样处理
2、方案2：使用long型值，根据模值重新计算得到新值跟原纪录比较
### 代码

```c
int ary[10000];

bool isPalindrome(int x){
    int index = 0;
    int left = 0;
    int right = 0;
    int y =0;

    if (x < 0) {
        return false;
    }

    if (x < 10) {
        return true;
    }

    do {
        y = x % 10;
        x = x / 10; 
        ary[index] = y;
        index ++;
    } while(x != 0);

    right = index - 1;
    for(;left ++, right --; left >= right) {
        if (ary[left] != ary[right]) {
            return false;
        }
    }
    return true;
}
```