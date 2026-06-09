```
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int pushI = 0;
    int popI = 0;
    int stack[1000];
    int i = 0;
    while (popI < poppedSize) {
        if (i == 0 || (i > 0 && stack[i - 1] != popped[popI])) {
            if (pushI < pushedSize) {
                stack[i++] = pushed[pushI++];
            } else {
                return false;
            }
        } else if (stack[i - 1] == popped[popI]) {
            popI++;
            i--;
            stack[i] = 0;
        }
    }
    if (pushI == pushedSize && i == 0) {
        return true;
    } else {
        return false;
    }
}
```
