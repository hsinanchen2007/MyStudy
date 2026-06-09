### 解题思路
如果字典能查到值，不需要计算就可以直接返回了

### 代码

```java
class Solution {
      HashMap<Integer,Integer> map=new HashMap<>();
    public int climbStairs(int n) {

    if (n==0){return 1;}
    if (n==1){return 1;}
    if (!map.containsKey(n)){
        map.put(n,climbStairs(n-1)+climbStairs(n-2));
    }
    else { return map.get(n);}
return climbStairs(n-1)+climbStairs(n-2);


    }
}
```