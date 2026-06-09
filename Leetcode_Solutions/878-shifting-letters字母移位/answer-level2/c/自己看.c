### 解题思路
执行用时 :
36 ms
, 在所有 C 提交中击败了
77.48%
的用户
内存消耗 :
7.3 MB
, 在所有 C 提交中击败了
100.00%
的用户

### 代码

```c
char * shiftingLetters(char * S, int* shifts, int shiftsSize)
{
    long num = 0;
    for (int i = 0; i < shiftsSize; i++) {
        num += shifts[i];
    }

    for (int i = 0; i < shiftsSize; i++) {
        S[i] = 'a' + (S[i] - 'a' + num) % 26;
        num -=  shifts[i];
    }    

    return S;
}
```