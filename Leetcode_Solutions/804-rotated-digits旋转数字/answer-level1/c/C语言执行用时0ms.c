### 解题思路
查表、循环排除347、2569至少1个即可

### 代码

```c
int good(int N)
{
    unsigned char tab[] = { 2, 2, 1, 0, 0, 1, 1, 0, 2, 1 };
    unsigned char place, rotated = 0;

    do {
        place = N % 10;
        if (tab[place] == 0) return 0;
        if (tab[place] == 1) rotated = 1;
    } while (N /= 10);

    return rotated;
}

int rotatedDigits(int N)
{
    int i, count = 0;
    for (i = 2; i <= N; i++) {
        if (good(i)) count++;
    }
    return count;
}

```