```java
public int[] constructArray(int n, int k) {
        int[] arr = new int[n];
        int s = 1, e = n, i = 0;
        while(s <= e) {
            if((i < k && i % 2 == 0) || (i >= k && (k - 1) % 2 == 0)) arr[i++] = s++;
            else arr[i++] = e--;
        }
        return arr;
}
```