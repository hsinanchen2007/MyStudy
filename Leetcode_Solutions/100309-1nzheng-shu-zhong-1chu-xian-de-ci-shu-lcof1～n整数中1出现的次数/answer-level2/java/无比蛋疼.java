### 解题思路
此处撰写解题思路
非常的坑爹，无比的蛋疼，int和long，就这么一个差异找问题找半天！！！！
思路大同小异，假设其中一位为1后计算该位左边数字出现次数加右边出现的次数，特殊情况需要考虑位置为1或0的情况。
### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        int sum=0;
        long precise = 1;

        while(n/precise!=0){
            long high = n/ (precise*10);
           long mid = (n / precise) % 10;
           long low = n % precise;
           
            if(mid == 0){
                sum += (high) * precise;
            }else if(mid ==1){
                sum += high*precise+low+1;
            }else if(mid > 1){
                sum += (high+1)*precise;
            }
             precise *= 10;
        }

        return sum;
    }
}
```