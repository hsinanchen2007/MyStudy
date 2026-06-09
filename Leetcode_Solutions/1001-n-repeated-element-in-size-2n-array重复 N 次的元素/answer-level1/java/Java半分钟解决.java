**半分钟解决**



根据题意，找到重复的那个数即可
```
 ArrayList<Integer> arr = new ArrayList<>();

        for (int i = 0; i < A.length; i++) {

            if(arr.contains(A[i])) return A[i];
            arr.add(A[i]);
        }
        return -1;
```
