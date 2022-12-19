从平方根开始。
设置两个数，第一个指针向上移动【二者乘积较小时】，第二个指针向下移动【二者乘积较大时】。
为了防止答案是相等的，第二个数需要稍微比第一个数大一点。

```
class Solution {
    public int[] closestDivisors(int num) {
        int numSqrt = (int)Math.sqrt(num); // Math.sqrt(num, 2) <= num
        int num1 = numSqrt;
        int num2 = numSqrt + 1;
        while (true){
            int product = num1 * num2;
            if (product < num + 1){
                num1++;
            } else if (product > num + 2){
                num2--;
            } else {
                return new int[]{num1, num2};
            }
        }
    }
}
```
