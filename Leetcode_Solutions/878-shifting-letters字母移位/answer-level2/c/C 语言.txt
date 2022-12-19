### 解题思路
此处撰写解题思路

### 代码

```c

char * shiftingLetters(char * S, int* shifts, int shiftsSize)
{
    for (int i = shiftsSize - 1; i > 0; i--) {
        shifts[i - 1] = shifts[i - 1] + shifts[i] % ('z' - 'a' + 1);
    }
    for (int i = 0; i < shiftsSize; i++) {
        S[i] = (S[i] - 'a' + shifts[i]) % ('z' - 'a' + 1) + 'a';
    }
    return S;
}
```