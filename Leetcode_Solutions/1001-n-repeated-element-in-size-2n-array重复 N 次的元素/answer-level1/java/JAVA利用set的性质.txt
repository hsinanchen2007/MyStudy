```
public int repeatedNTimes(int[] A) {
        // 放到set里面
        Set set = new HashSet();
        for (int i = 0; i < A.length; i++) {
            // 把元素放进去，然后查看set的大小是否有改变
            int preSize = set.size();
            set.add(A[i]);
            if (set.size() == preSize){
                // 大小没变，说明放进去的元素有问题，
                return A[i];
            }

        }
        return -1;
    }
```
