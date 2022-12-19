### 解题思路
思路：由于是找等差子数组，所以只需求出a1,a2两个的差值，保存起来，然后用a3-a2的差值进行对比，如果相同，说明a1,a2,a3是等差子数组，如果a4-a3与前面的差值不一样，说明a4不属于这一组，将a4-a3的值存起来，然后用a5-a4的值与其进行比较，如此遍历一遍即可，每次遇到差值相同的进行count计数，不相同的就查看count是否达到3个，达到了就用排列组合算这count个数能凑成几个子数组，比如：1,2,3,4,5,6,8,10，前6个数的差都为1，到8时，差变成了2，此时count=6，前6个数的数组个数为6*(6+1)/2，再与后面的子数组个数累加即可。

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if(A.length < 3){
            return 0;
        }
        int count = 1;
        int total = 0;
        int temp = 0;
        //标识为第二个与第一个元素的差
        boolean first = true;
        int n = 0;
        for(int i=1; i<A.length; i++){
            if(first || A[i] - A[i-1] == temp){
                temp = A[i] - A[i-1];
                first = false;
                count++;
            }else{
                //出现差值不一样的情况时，判断出现差值一样的个数是否大于3个
                if(count >= 3){
                    n = count-3 + 1;
                    total += n*(n+1)/2;
                }
                temp = A[i] - A[i-1];
                //此时已经有两个数了，所以置为2
                count = 2;
            }

            
        }
        n = count - 3 + 1;
        total += n*(n+1)/2;
        return total;

    }
}
```