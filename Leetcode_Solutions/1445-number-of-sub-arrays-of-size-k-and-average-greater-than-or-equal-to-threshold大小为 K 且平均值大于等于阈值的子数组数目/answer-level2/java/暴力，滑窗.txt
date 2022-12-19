### 解题思路
心态炸裂，做的时候一直以为子数组可以是不连续的，硬是没做出来，出来一看题解整个人都不好了，原来子数组是特么的连续的啊，这不就两个循环结束的事🐎

### 代码
#### 暴力

```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int res = 0;
        for (int i = 0; i < arr.length - k + 1; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += arr[j];
            }
            if (sum >= k * threshold) res++;   
        }
        return res;
    }
}
```
#### 滑窗
```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int res = 0;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum >= k * threshold) res++;
        for (int i = 1; i < arr.length - k + 1; i++) {
            sum -= arr[i - 1];
            sum += arr[i - 1 + k];
            if (sum >= k * threshold) res++;   
        }
        return res;
    }
}
```