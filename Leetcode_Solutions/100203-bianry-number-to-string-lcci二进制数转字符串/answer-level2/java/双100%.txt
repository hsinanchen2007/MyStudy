暴力法解决

### 代码

```java
class Solution {
    public String printBin(double num) {
        StringBuilder sb=new StringBuilder();
        sb.append("0.");//加入小数点之前部分
        double cur=0;
        double tried=0.5;//设置每次的加数
        while (tried>=0.5/(Math.pow(2,31))){//停止条件，不长于小数点后32位
            if (num-cur==tried){//正好与结果相等，直接输入
                sb.append('1');
                return sb.toString();
            }
            else if (num-cur<tried){//此时加上就会大于结果，不加
                sb.append('0');
                tried*=0.5;
            }
            else{//此时可以加
                sb.append('1');
                cur+=tried;
                tried*=0.5;
            }
        }
        return "ERROR";
    }
}
```