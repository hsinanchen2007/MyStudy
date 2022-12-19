有效位置j应该满足的条件是：```max(arr[0...j]) <= min(arr[j...n-1])```
```
// time complexity O(n)
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int[] rightMax = new int[n];
        rightMax[n-1] = Integer.MAX_VALUE;
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = Math.min(rightMax[i + 1], arr[i + 1]);
        }
        int res = 0, max = arr[0];
        for(int i = 0 ; i < n ; i++){
            max = Math.max(max, arr[i]);
            if(max <= rightMax[i]){
                res++;
            }
        }
        return res;
    }
}
```