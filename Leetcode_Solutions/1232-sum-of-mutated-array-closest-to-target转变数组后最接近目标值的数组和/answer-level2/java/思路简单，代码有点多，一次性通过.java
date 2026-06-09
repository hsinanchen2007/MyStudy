```
class Solution {
    private int higher(int[] arr, int val) {
        int i = 0; 
        int j = arr.length - 1;
        while(i < j) {
            int mid = (i + j) / 2;
            if (arr[mid] >= val) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
    
    private int sum(int[] arr, int index, int val) {
        int n = arr.length - index;
        int s = n * val;
        if (index == 0) {
            return s;
        }
        return s + arr[index - 1];
    }
    
    public int findBestValue(int[] arr, int target) {
        Arrays.sort(arr);
        int len = arr.length;
        int sum = 0;
        for(int a : arr) {
            sum += a;
        }
        
        if (sum <= target) {
            return arr[len - 1];
        }
        
        int[] prefix = new int[len];
        prefix[0] = arr[0];
        for(int i = 1; i < len; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
                
        int i = 0;
        int j = arr[len - 1];
        while(i < j) {
            int mid = (j - i) / 2 + i;
            int index = higher(arr, mid);
            int s = sum(prefix, index, mid);
            if (s == target) {
                return mid;
            } else if (s > target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
                
        if (i == 0) {
            return 0;
        }
        
        int index1 = higher(arr, i);
        int s1 = sum(prefix, index1, i);
        
        int index2 = higher(arr, i - 1);
        int s2 = sum(prefix, index2, i - 1);
        if (target - s2 <= s1 - target) {
            return i - 1;
        }
        
        return i;
    }
}
```
