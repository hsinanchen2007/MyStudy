### 代码

```java
class Solution {
      public int[] getLeastNumbers(int[] arr, int k) {
        quickSort(arr, 0, arr.length - 1);
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = arr[i]; 
        }
        return result;
    }

    public void quickSort(int a[], int l, int r) {
        if(l>r) {
            return;
        }
        int i = l; int j = r; int key = a[l];
        while (i<j) {
            while (i<j && a[j] > key) j--;
            if(i<j) {
                a[i] = a[j];
                i++;
            }
            while(i<j && a[i] < key) i++;
            if(i<j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = key;
        quickSort(a,i+1,r);
        quickSort(a,l,i-1);
    }
}
```