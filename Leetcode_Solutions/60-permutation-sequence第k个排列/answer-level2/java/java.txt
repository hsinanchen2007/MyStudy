### 解题思路
此处撰写解题思路
### 代码

```java
class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> list = new ArrayList<>();
        for(int i = 1; i <= n; i++) {
            list.add(i);
        }
        return getPermutationByList(n, k, list);
    }
    public String getPermutationByList(int n, int k, List<Integer> list) {
        StringBuilder stringBuilder = new StringBuilder();
        if(n == 1){return list.get(0).toString();}
        int quo = (k - 1) / factorial(n - 1);
        int rem = (k - 1) % factorial(n - 1);
        stringBuilder.append(list.get(quo));
        list.remove(quo);
        stringBuilder.append(getPermutationByList(n - 1, rem + 1, list));
        return new String(stringBuilder);
    }
    public int factorial(int n) {
        if(n == 1){
            return 1;
        }
        return n * factorial(n - 1);
    }
}
```