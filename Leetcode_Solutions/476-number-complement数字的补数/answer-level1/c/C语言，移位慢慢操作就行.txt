执行用时 : 4 ms, 在Number Complement的C提交中击败了96.47% 的用户

内存消耗 : 6.8 MB, 在Number Complement的C提交中击败了73.17% 的用户

```c
int findComplement(int num){
    int res = 0;
    int tmp = 0;
    int idx = 0;
    while(num)
    {
        tmp = (~num) & 0x01;
        num = num >> 1;

        res += tmp << idx;
        idx++;
    }
    return res;
}
```