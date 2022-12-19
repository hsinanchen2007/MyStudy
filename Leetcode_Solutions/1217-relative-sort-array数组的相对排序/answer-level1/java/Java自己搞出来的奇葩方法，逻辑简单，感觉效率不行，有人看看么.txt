```
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int l = arr1.length;
        int[] result = new int[l];
        int count = 0;
        for(int i = 0; i < arr2.length; i++) {
            for(int j = 0; j < l; j++) {
                if(arr2[i] == arr1[j]) {
                    result[count] = arr2[i];
                    count++;
                    arr1[j] = 1001;
                }
            }
        }
        int count2 = 0;
        int[] more = new int[l - count];
        for(int p : arr1) {
            if(p != 1001) {
                more[count2] = p;
                count2++;
            }
        }
        Arrays.sort(more);
        for(int s = 0; s < more.length; s++) {
            result[count] = more[s];
            count++;
        }
        return result;
    }
}
```
