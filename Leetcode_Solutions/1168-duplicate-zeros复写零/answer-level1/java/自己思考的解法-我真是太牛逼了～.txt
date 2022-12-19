```java
class Solution {
    public void duplicateZeros(int[] arr) {
        int count = 0;
        // 统计下 0 的个数，也表示往后要移动的间距；
        for (int item : arr) {
            if (item == 0) {
                count++;
            }
        }
        for (int i = arr.length - 1; i >= 0; --i) {
            // 如果是 0 的话，显然他要往后移动的间距是 count - 1 （不算自身）
            if (arr[i] == 0) {
                --count;
            }
            // 向后移动，判断边界；
            if (i + count < arr.length) {
                arr[i + count] = arr[i];
                // 如果是 0 的话，后面的那个元素也要被改成 0 
                if (i + count + 1 < arr.length && arr[i] == 0) {
                    arr[i + count + 1] = 0;
                }
            }
        }
    }
}
```
