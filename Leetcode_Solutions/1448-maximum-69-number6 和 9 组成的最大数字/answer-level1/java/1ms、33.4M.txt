``` java
class Solution {
    public int maximum69Number (int num) {
        // size为n的位数；mark用来标记最高位的6到末尾的位数；
        int x = num, size = 0, mark = 0;
        // 个位数直接返回
        if(num == 6 || num == 9)
            return 9;
        // 从后往前找6
        while(num > 0){
            size++;
            if(num % 10 == 6)
                mark = size;
            num /= 10;
        }
        // 若没有6直接返回num即可
        return mark == 0 ? x : x + 3 * (int)Math.pow(10, mark - 1);
    }
}
```
