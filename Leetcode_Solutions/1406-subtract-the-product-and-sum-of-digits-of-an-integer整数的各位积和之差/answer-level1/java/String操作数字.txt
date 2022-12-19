### 解题思路
用String提供的API操作int型

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
                String str_n=String.valueOf(n);
        char [] chars_n=str_n.toCharArray();
        int sum=0;
        int mul=1;
        for(int i=0;i<chars_n.length;i++){
            sum+=Integer.parseInt(String.valueOf(chars_n[i]));
            mul*=Integer.parseInt(String.valueOf(chars_n[i]));
        }
        return mul-sum;
        
    }
}
```