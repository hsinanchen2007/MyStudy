### 解题思路
本题采用贪心思路，1、如果字符串按照数字大小升序排列，只需要删除最后K个字符即可；2、如果非升序排列，需要从前到后遍历，删除字符串中每个逆序排列的字符。由于是从前到后遍历，所以先删除的一定是高位的数字，可以保证删除后得到的最终数字最小。
举例来说：如果字符串num = "123456789", k = 3，我们只需要删除最后3个数字，得到"123456".
         如果字符串num = "1432219", k = 3，需要从前到后遍历查找逆序数字，进行删除，第一个逆序数字为'4'，第二个逆序数字为'3'，第三个逆序数字为第二个'2'，最后得到"1219"。
所以可以采用栈实现，每次遍历，判断如果栈非空，且当前数字大于栈顶数字，且k还有剩余（不为0），将栈顶数字出栈。最后将当前数字入栈。
如果遍历完成后，k仍有剩余，则依次将栈顶数字出栈。最后栈中保存的数字即为所求。按照从栈底到栈顶输出即可。
注意：特判场景，如果最后所有数字均出栈，即栈为空，需要返回"0"。

### 代码

```c
#define MAX_SIZE 10002

typedef struct{
    int data[MAX_SIZE];
    int top;
}Stack;

Stack stk;

void init()
{
    memset(stk.data, 0, sizeof(int) * MAX_SIZE);
    stk.top = 0;
    return;
}

void push(int x) 
{
    if (stk.top > MAX_SIZE - 1) {
        return;
    }
    stk.data[stk.top] = x;
    stk.top++;
    return;
}

void pop()
{   
    if (stk.top == 0) {
        return;
    }

    stk.top--;
    return;
}

int top()
{
    return stk.data[stk.top - 1];
}

int empty()
{
    if (stk.top == 0) {
        return 1;
    }
    return 0;
}

char * removeKdigits(char * num, int k)
{
    char *res = NULL;
    int len = 0;
    int i;
    int cnt = 0;

    if (num == NULL || k == 0) {
        return num;
    }

    len = strlen(num);
    init();
    res = (char *)malloc(sizeof(char) * (len + 1));
    push(num[0] - '0');
    for (i = 1; i < len; i++) {
        while ((empty() == 0) && ((num[i] - '0') < top()) && (k > 0)) {
            pop();
            k--;
        }
        push(num[i] - '0');
    }

    while (k > 0) {
        pop();
        k--;
    }
   
    for (i = 0; i < stk.top; i++) {
        if ((stk.data[i] == 0) && (cnt == 0)) {
            continue;
        }
        res[cnt] = stk.data[i] + '0';
        cnt++;
    }
    if (cnt == 0) {
        res[0] = '0';
        cnt++;
    }
    res[cnt] = '\0';
    return res;
}
```