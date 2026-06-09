### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    static int mod = 1000000007;
    public int numWays(int n) {
        HashMap<Integer,Integer> map = new HashMap<>();
        return helper(n,map);
    }

    public static int helper(int n,HashMap<Integer,Integer> map){
        if(n <= 1){
            return 1;
        }

        if(n==2){
            return 2;
        }

        if(map.containsKey(n)){
            return map.get(n);
        }else{
            int value = (helper(n-1, map) + helper(n-2, map))%mod;
            map.put(n, value);
            return value;
        } 
    }
}
```