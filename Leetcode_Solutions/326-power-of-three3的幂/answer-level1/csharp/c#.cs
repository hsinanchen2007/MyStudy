```
public class Solution {
    public bool IsPowerOfThree(int n) {
        if(n==1||n==3)
            {
                return true;
            }
            int a = 0;
            int b = 0;
            while(n>=3&&b==0)
            {
                a = n / 3;
                b = n % 3;
                n = n / 3;
            }
            if(a==1&&b==0)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
}
```
