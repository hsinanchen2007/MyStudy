### 解题思路
随机法

### 代码

```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        Random random =new Random();
        int a=random.nextInt(n);
        int b=n-a;
        while(hasZero(a)||hasZero(b))
        {
            a=random.nextInt(n);
            b=n-a;
        }
        int[] res={a,b};
        return res;
    }

    boolean hasZero(int n)
    {
        String s=String.valueOf(n);
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='0')
                return true;
        }
        return false;
    }
}
```