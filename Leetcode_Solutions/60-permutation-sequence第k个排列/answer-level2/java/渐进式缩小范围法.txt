
```java

class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder builder = new StringBuilder();
        List<Integer> numbers = new LinkedList<Integer>();
        
        for(int i = 1;i <= n;i++){
           numbers.add(i);
        }
        
        // int groupCount = fac(n) / n;
        for(int j = 0;j <= n - 1;j++){
            int groupCount = fac(n - j) / (n - j);
            int temp = (k - 1) / groupCount;
            builder.append(numbers.get(temp));
            numbers.remove(temp);
            k -= temp * groupCount;
        }
        return builder.toString();
        
    }
    
    public int fac(int n){
        int result = 1;
        /** execution takes 26ms */
        
        // for(int i=1;i<=n;i++){
        //     result *= i;
        //     System.out.println(i + ":" + result);
        // }
        // return result;
        
        /** execution takes 2ms */
        return n <= 1 ? 1 : n * fac(n - 1);
    }
}

```

` create 2019-10-25 10:01:32 ， k12 `