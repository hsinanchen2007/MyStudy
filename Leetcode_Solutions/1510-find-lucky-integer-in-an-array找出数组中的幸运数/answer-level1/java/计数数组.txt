用计数数组计数，然后返回其中的次数等于数字且最大的那个

```
class Solution {
    public int findLucky(int[] arr) {
        int[] count = new int[500];
        int max = 0, ans = -1;
        for(int c : arr){
            count[c]++;
            max = max > c ? max : c;
        }
        for(int i=1; i<=max; i++){
            if(count[i]==i){
                ans = ans > i ? ans : i;
            }
        }
        return ans;
    }
}
```
