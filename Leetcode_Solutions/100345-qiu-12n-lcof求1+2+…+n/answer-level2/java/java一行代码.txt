java中Math.pow输出的是double类型,需要强转成int;
```
class Solution {
    public int sumNums(int n) {
        return (int)(Math.pow(n, 2) + n) >> 1;
    }
}
```
