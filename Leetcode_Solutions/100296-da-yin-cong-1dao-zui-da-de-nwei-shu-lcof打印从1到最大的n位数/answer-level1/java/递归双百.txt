```
class Solution {
    public int[] printNumbers(int n) {
        int max = getMax(n);
        int[] res = new int[max];
        for(int i = 0; i < res.length; i++) res[i] = i+1;
        return res;
    }
    private int getMax(int n){
        if(n == 1) return 9;
        return 10*getMax(n-1)+9;
    }
}
```
