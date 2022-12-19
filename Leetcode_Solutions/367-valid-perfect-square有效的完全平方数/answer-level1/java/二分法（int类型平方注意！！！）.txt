### 解题思路
1、标准的二分法查找
2、注意：int类型平方时，要先转double，再计算。如果先计算再转会计算异常 例如：i = 202050

### 代码

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        int low = 0;
        int high = num - 1;
        int mid;
        if(num == 1){
            return true;
        }
        while (low<high){
            mid = low+((high-low)>>1);
            /**
             * int 类型平方，注意要先转double，再做计算
             * 如果先计算再转会有异常：如下方法则会出现计算异常
             *  double s = (double)mid * mid; //错误的！！！
             *
             */
            double s = (double)mid * (double)mid;
            if(s < num){
                low = mid+1;
            }else if(s > num){
                high = mid;
            }else if(s == num) {
                return true;
            }
        }
        return false;
    }
}
```