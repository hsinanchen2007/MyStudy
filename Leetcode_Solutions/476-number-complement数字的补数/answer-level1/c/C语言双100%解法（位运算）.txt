先全部取反然后反转前导1
```
// 执行用时 : 0 ms, 在所有 C 提交中击败了 100.00 % 的用户
// 内存消耗 : 5 MB, 在所有 C 提交中击败了 100.00 % 的用户
int findComplement(int num)
{
    int count = 0;
    int mask = 0x80000000;
    num = ~num;

    while (num & mask)//find the first digit of origninal number
    {
        num &= ~mask;
        mask >>= 1;
    }
    return num;
}
```
