talk is cheap,show me the code!

```java
public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for(int i : C){
            for(int j : D)
                hashMap.put(i+j, hashMap.getOrDefault(i+j, 0)+1);
        }
        int res = 0;
        for(int i : A){
            for (int j : B){
                if (hashMap.containsKey(0-i-j)){
                    res+=hashMap.get(0-i-j);
                }
            }
        }
        return res;
    }
```
