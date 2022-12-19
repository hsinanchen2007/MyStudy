    这个题除了0,1两个排除循环做判断外，其他的2-n的范围的数通过while循环.
    循环内部为可整除2的参数n新的赋值=除2后的结果，直到没有被整除的空间j即
    n==1时，未跳出循环，返回true.在这个途中若发现新的n值无法整除2，跳出循环。返回falsefalse.
```java []
 public boolean isPowerOfTwo(int n) {
        if(n==0)return false;
        if(n==1)return true;
        while(n%2==0){
            n=n%2;
            if(n==1)return true;
        }
        return false;
    }
```



