### 解题思路
此处撰写解题思路
跟爬楼梯的题目类似，思路是一位数字+二位数字

### 代码

```c

int DFS(int num)
{
    if (num >= 0 && num < 10) {
        return 1;
    }

    int result = 0;

    // 一位数字
    result += DFS(num/10);

    // 二位数字
    int ret2 = num / 100;
    int val2 = num % 100;
    if (val2 >= 10 && val2 <= 25) {
        result += DFS(ret2);
    }
    
    return result;
}

int translateNum(int num){
    return  DFS(num);
}

```