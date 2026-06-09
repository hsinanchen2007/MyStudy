
双指针的应用
a^2+b^2=r^2(r^2=c,c=Math.sqrt(c))，缩小范围。
```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int i=0,j=(int)Math.sqrt(c);
        while(i<=j){
            int powSum = i*i+j*j;
            if(powSum == c){
                return true;
            }else if(powSum <c){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
}

```