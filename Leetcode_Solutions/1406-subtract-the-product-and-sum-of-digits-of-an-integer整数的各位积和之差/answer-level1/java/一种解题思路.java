### 解题思路
拿输入的数字当循环的判断，然后分解数字并计算即可.

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int result=0;
        int s1=1;
        int s2=0;
        int i=0;
        while(n>0){
            i=n%10;
            n=n/10;
            s1=s1*i;
            s2=s2+i;
        }
        result=s1-s2;
        return result;
    }
}
```