### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        int rev = 0;
        while(x!=0){
            int pop = x%10;
            if(x>0 && (rev >Integer.MAX_VALUE/10 ||(rev==Integer.MAX_VALUE/10 && pop > Integer.MAX_VALUE%10))){
                rev =0;break;
            }
            if(x<0 && (rev <Integer.MIN_VALUE/10 ||(rev==Integer.MIN_VALUE/10 && pop < Integer.MIN_VALUE%10))){
                rev =0;break;
            }
            rev = rev*10+pop;
            x/=10;
        }
        return rev;

    }

}
```