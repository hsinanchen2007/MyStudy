这就是个数学题,有两个数A和B交换值:
    最初的AB记为A。B。
    A=A0+B0
    B=B-A=B0-A0-B0=-A0
    A=A+B=A0+B0-A0=B0
    B=-B=A0


执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
38.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户




```
    public int[] swapNumbers(int[] numbers) {
        numbers[0]+=numbers[1];
        numbers[1]-=numbers[0];
        numbers[0]+=numbers[1];
        numbers[1]=-numbers[1];
        return numbers;
    }
```
