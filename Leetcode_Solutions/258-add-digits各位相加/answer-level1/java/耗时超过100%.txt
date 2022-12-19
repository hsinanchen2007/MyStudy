```
class Solution {
    public int addDigits(int num) {
        int len = 1;
        while(num > 9){
            num = num/10 + num % 10;
        }
        return num;

    }
}
```
