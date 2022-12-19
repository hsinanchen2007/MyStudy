### 解题思路
![image.png](https://pic.leetcode-cn.com/1abaed1af28edb31c6b3f1172a2262d65a02fdf665743dc045edbcb42a79e076-image.png)
思路：尝试pushed入栈， 遇到pushed[i] == popped[i]时跳过(因为popped[i]肯定没有入栈)；
如果pushed[i] != popped[j]时，要检查popped[j]是否在栈顶上，如果在就出栈并且j++，继续检查popped[j]是否在栈顶上，一直到栈为空或者popped[j]不在栈顶上为止。再检查popped[j]是否在栈上，如果还在则说明序列不符合要求返回，否则把pushed[i]入栈后继续往后找新的元素。

### 代码

```c
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    //栈后进先出, 对于popped里的i位置的元素a[i]而言，在pushed里a[i]前面的元素的出栈顺利是固定的，但出栈的时机不定. 对i-1，pushed里a[i] ~ a[i - 1]的元素出栈顺序是固定的

    //思路：尝试pushed入栈遇到popped[i]时跳过(因为popped[i]肯定没有入栈)，
    //如果pushed[i] != popped[j]时，要检查popped[j]是否在栈顶上，如果在就出栈并且j++，继续检查popped[j]是否在栈顶上，一直到栈为空或者popped[j]不在栈顶上为止。再检查popped[j]是否在栈上，如果还在则说明序列不符合要求返回，否则把pushed[i]入栈后继续往后找新的元素。
    bool retBool = true;
    int popId = 0;
    int stack[1024];
    int stackTop = 0;
    int popOutStack[1024] = {0};

    for (int i = 0; i < pushedSize; i++) {
        //检查popped[popId]是否已在栈上，如果在则判断并出栈
        while(stackTop > 0 && stack[stackTop - 1] == popped[popId]) {
            stackTop--;//出栈
            popId++; //继续检查下一个pop是否在栈上
        }

        //检查popped[popId]是否在栈上，如果还在则说明是错误的序列
        for (int i = 0; i < stackTop - 1 && popOutStack[popId] == 0; i++) {
            if (stack[i] == popped[popId]) {
                retBool = false;
                break;
            }
        }

        if (!retBool) {
            break;
        }

        popOutStack[popId] = 1;

        //popId肯定不在栈上了
        if (pushed[i] == popped[popId]) {
            popId++;
            continue; //两边都跳过，继续检查后面的元素
        } else {
            //pushed[i]入栈，pushed继续往后面扫描
            stack[stackTop++] = pushed[i];
        }
    }

    //如果popId < poppedSize, 则顺序出栈跟剩余的popped比较
    if (retBool && popId < poppedSize) {
        // printf("comp: stktop:%d, popId:%d\n", stackTop, popId);
        while(stackTop > 0 && stack[stackTop - 1] == popped[popId]) {
            stackTop--;
            popId++;
        }

        if (popId < poppedSize) {
            // printf("popId:%d stackTop:%d\n", popId, stackTop);
            retBool = false;
        }
    }

    return retBool;
}
```