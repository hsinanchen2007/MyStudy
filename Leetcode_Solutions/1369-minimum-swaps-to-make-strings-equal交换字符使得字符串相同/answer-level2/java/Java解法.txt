```
/**
 **   思路：统计(x,y)和(y,x)对的数量，如若都是偶数，则(x,y)(y,x)两两可以相互调换即可;如若是奇数，则最后
 **         必然剩余一对(x,y)(y,x),这种情况需要调换两次,则在统计的基础上+2即可;其他情况，则不可能调换成功
**/
class Solution {
    public int minimumSwap(String s1, String s2) {
        int sum=0,sum1=0;
        for (int i=0;i<s1.length();i++) {
            if (s1.charAt(i)=='x'&&s1.charAt(i)!=s2.charAt(i)) {
                // x,y对的数量
                sum++;
            } else if (s1.charAt(i)=='y'&&s1.charAt(i)!=s2.charAt(i)) {
                // y,x对的数量
                sum1++;
            }
        }
        
        int mod=sum%2;
        int mod1=sum1%2;
        
        if (mod!=mod1) {
            return -1;
        } else {
            return (mod==1)?(sum/2+sum1/2+2):(sum/2+sum1/2);
        }
    }
}

```
