```
public int[] subSort(int[] array) {
        int len = array.length;
        if (len < 2) {
            return new int[] {-1, -1};
        }
        int[] arr = new int[len];
        
        arr[len-1] = array[len-1];
        for(int i = len - 2; i >= 0; i--) {
            arr[i] = Math.min(array[i], arr[i+1]);    
        }
        
        int[] res = new int[2];
        int index = 0;
        for(index = 0; index < len; index++) {
            if (array[index] != arr[index]) {
                break;
            }
        }
        if (index == len) {
            res[0] = res[1] = -1;
            return res;
        }
        res[0] = index;
        arr[0] = array[0];
        for(int i = 1; i < len; i++) {
            arr[i] = Math.max(array[i], arr[i-1]);
        }
        for(index = len - 1; index >= 0; index--) {
            if (array[index] != arr[index]) {
                break;
            }
        }
        res[1] = index;
        return res;
    }
```
