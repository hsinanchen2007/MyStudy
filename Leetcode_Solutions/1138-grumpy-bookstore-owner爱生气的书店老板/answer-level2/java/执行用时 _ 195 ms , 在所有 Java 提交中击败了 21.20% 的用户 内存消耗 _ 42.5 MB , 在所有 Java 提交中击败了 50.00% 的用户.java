### 解题思路
不大会用滑动窗口，思路参照了题解，但第二步使用的是最为朴素的求解前X个数的和。

### 代码

```java
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int sum1 = 0;
        for(int i = 0;i<grumpy.length;i++) {
            if(grumpy[i]==0) {
                sum1+=customers[i];
                customers[i]=0;
            }
        }




        int biaozhi = 0;
        int max = 0;
        for(int i = 0;i<X;i++) {
            max+=customers[i];
        }
        
        for(int i = 1;i<=customers.length-X;i++) {
            int l = X-1;
            int sum = 0;
            int j = i;
            while(l>=0) {
                 sum+=customers[j];
                 j++;
                 l--;
            }    


            if(max<=sum) {
                biaozhi = i;
                max = sum;
            }
        }
        

        return max+sum1;
        
    }
}
```