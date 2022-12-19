击败双100%

```
void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
    
    void smallestK2(int[] arr, int i, int j, int k) {
        int mid = (i + j) / 2;
        int t = arr[mid];
        arr[mid] = arr[i];
        arr[i] = t;
        
        int lo = i + 1;
        int hi = j;
        while(lo <= hi) {
            while(lo <= hi && arr[lo] <= t) {
                lo++;
            }
            while(hi >= lo && arr[hi] > t) {
                hi--;
            }
            
            if (lo < hi) {
                swap(arr, lo, hi);
                lo++;
                hi--;
            }
        }
        
        swap(arr, i, lo - 1);
        int cur = lo - 1;
        int n = cur - i + 1;
        
        if (n == k) {
            return;
        } else if (n > k) {
            smallestK2(arr, i, cur - 1, k);
        } else {
            smallestK2(arr, cur + 1, j, k - n);
        }
    }
    
    public int[] smallestK(int[] arr, int k) {
        if (k == 0) {
            return new int[0];
        }
        
        smallestK2(arr, 0, arr.length - 1, k);
        
        int[] res = new int[k];
        for(int i = 0; i < k; i++) {
            res[i] = arr[i];
        }
        
        return res;
    }
```


