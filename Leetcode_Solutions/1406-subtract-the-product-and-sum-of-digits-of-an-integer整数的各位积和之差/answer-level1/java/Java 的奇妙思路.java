# 字符串是个好东西
刚拿到这个题就冒出了这个思路，后来用了比较正经的思路，发现内存上没啥区别，执行时间都是100%。

```java
class Solution {
    public int subtractProductAndSum(int n) {
 
        int multi = 1;
        int sum = 0;

        String s = String.valueOf(n);
        for(int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            multi *= c-'0';
            sum += c-'0';
        }

        return multi - sum;

    }
}
```

