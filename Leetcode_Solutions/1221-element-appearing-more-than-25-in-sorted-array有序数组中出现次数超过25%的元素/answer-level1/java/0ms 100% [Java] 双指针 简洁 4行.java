思路：
    - 根据arr.length找到超过25%处的下标
    - 保持固定距离（25%个数）
    - 如若两个指针所指的数相等及为所求
```
public int findSpecialInteger(int[] arr) {
        int before = arr.length / 4;
        for(int i = 0; before < arr.length; i++, before++){
            if(arr[i] == arr[before]) return arr[i];
        }
        return arr[arr.length-1];
    }
```

