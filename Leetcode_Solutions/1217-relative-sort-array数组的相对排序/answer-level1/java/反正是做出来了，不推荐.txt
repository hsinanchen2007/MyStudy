### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int len = arr1.length;
        int arr4[] = new int[len];
        int k = 0;
        //arr2前k位数字
        for (int i = 0; i <arr2.length ; i++) {
            for (int j = 0; j <arr1.length ; j++) {
                if(arr2[i] == arr1[j]){
                    arr4[k] = arr1[j];
                    k++;
                }
            }
        }
        int left = len - k ;
        int arr3[] = new int[left];
        int m = 0;
        String string = Arrays.toString(arr2);
        List<Integer> ints = new ArrayList<>();
        Map map = new HashMap();
        for (int i = 0; i < arr2.length; i++) {
            map.put(arr2[i],1);
        }
        for (int i = 0; i <len ; i++) {
            if(map.get(arr1[i])==null){
                arr3[m] = arr1[i];
                m++;
            }
        }
        Arrays.sort(arr3);
        int n = 0;
        for (int i = k; i < arr1.length ; i++) {
            arr4[i] = arr3[n];
            n++;
        }
        return arr4;
    }
}
```