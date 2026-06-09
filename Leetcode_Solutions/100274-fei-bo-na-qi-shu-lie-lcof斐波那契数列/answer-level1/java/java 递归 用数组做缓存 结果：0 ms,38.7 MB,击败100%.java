### 解题思路
献丑，主要加了数组cache保存递归过程中的值，以免重复计算

### 代码

```java
class Solution {
    public static int fib(int n){
        int[] cache = new int[n];
        return subFib(n,cache);
    }
    private static int subFib(int n,int[] cache){
        int n1;//subFib(n-1)
        int n2;//subFib(n-2)
        if(n==0){
            return 0;
        }else if(n==1 || n==2){
            return 1;
        }else{
            //若缓存数组中已有数据，则直接取，没有递归计算
            if (cache[n-2] == 0){
                n1 = subFib(n-1,cache);
                cache[n-2] = n1;
            }else {
                n1 = cache[n-2];
            }
            if (cache[n-3] ==0){
                n2 = subFib(n-2,cache);
                cache[n-3] = n2;
            }else {
                n2 = cache[n-3];
            }
            return (n1 + n2)%1000000007;
        }

    }
    
}
```