```
public static int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] tmp = new int[1001];
        for (int i = 0; i < arr1.length; i++) {
            tmp[arr1[i]]++;
        }
        int index = 0;
        for (int i = 0; i < arr2.length; i++) {
            int num = arr2[i];
            for (int j = 0; j < tmp[num]; j++) {
                arr1[index++] = num;
            }
            tmp[num] = 0;
        }
        for (int i = 0; i < tmp.length; i++) {
            if (tmp[i] != 0) {
                for (int j = 0; j < tmp[i]; j++)
                    arr1[index++] = i;
            }
        }

        return arr1;
```


*执行用时 :1 ms, 在所有 Java 提交中击败了99.83%的用户*

*内存消耗 :35.9 MB, 在所有 Java 提交中击败了100.00%的用户*