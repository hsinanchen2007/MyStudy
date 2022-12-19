### 解题思路
使用两个栈，正数栈和负数栈；
循环每个小行星，如果是正，直接入栈；
只有是负时，进行相应的判断处理；
使用一个while循环，判断两个栈的栈顶，分为三种情况：1正栈顶爆炸；2负数栈顶爆炸；3都爆炸；
三种情况中，只有正数栈顶爆炸时，才继续while循环；其余情况爆炸之后进行下一个行星判断；

### 代码

```c
int g_stack1[10000];
int g_stack2[10000];

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    int i, j;
    int top1 = -1;
    int top2 = -1;
    for (i = 0; i < asteroidsSize; i++) {
        if (asteroids[i] > 0) { // 入栈
            top1++;
            g_stack1[top1] = asteroids[i];
        } else if (asteroids[i] < 0) {
            top2++;
            g_stack2[top2] = asteroids[i]; // 入栈stack2
            while (top1 >= 0 && top2 >= 0) {
                int t1 = g_stack1[top1];
                int t2 = g_stack2[top2]; // 取栈顶元素
                t2 = t2 * (-1); 
                if (t1 > t2) { // t2爆炸
                    top2--;
                    break; 
                } else if (t1 == t2) {
                    top1--;
                    top2--;
                    break;
                } else {
                    top1--;  // 只有整数栈栈顶爆炸之后才循环，其余continue;
                }
            }
        }
    }
    int *res = (int*)malloc(sizeof(int) * asteroidsSize);
    int idx = 0;
    int len = top2;
    while (top2 >= 0) {
        res[idx++] = g_stack2[len - top2];
        top2--;
    }
    len = top1;
    while (top1 >= 0) {
        res[idx++] = g_stack1[len - top1];
        top1--;
    }
    *returnSize = idx;
    return res;    
}
```