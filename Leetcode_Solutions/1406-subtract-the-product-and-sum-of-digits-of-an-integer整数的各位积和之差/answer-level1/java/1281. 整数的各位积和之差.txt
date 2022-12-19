### 解题思路
常规思路：每次求余与整除再分别加到和上与乘到积上，唯一要注意的是每次整除之后判断结果是否大于零，从而减少后续不必要的计算。执行时间和内存消耗在所有Java提交中超过100%的用户。

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int subtract = 0;
        int product = 1;
        int sum = 0;
        
        for(int i = 0; i < 6; i++){
        	if((subtract = n / 10) > 0){
        		int remainder = n % 10;
        		product *= remainder;
        		sum += remainder;
        		n = subtract;
        	}
        	else{
        		product *= n;
        		sum += n;
        		break;
        	}
        }
        return product - sum;
    }
}
```