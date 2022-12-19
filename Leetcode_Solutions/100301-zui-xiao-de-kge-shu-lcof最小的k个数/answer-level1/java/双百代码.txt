```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if(k == 0){
            return new int[]{};
        }
        int[] tables = new int[10001];
        for(int val : arr){
            tables[val]++;
        }
        int[] res = new int[k];
        int count = 0;
        for(int i = 0; i < tables.length; i++){
            while(tables[i]!=0){
                res[count++] = i;
                tables[i] = tables[i]-1;
                if(count == k) return res;
            }
        }
        return res;
    }
}
```
