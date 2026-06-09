### 解题思路
二分法+双指针

### 代码

```java
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> list = new ArrayList<>();
        if (arr == null || arr.length == 0) {
            return list;
        }

        int right = findUpperClosest(arr, x);
        int left = right - 1;

        for (int i = 0; i < k; i++) {
            if(isLeftCloser(arr, left, right, x)){
                list.add(0, arr[left]);
                left--;
            } else {
                list.add(arr[right]);
                right++;
            }
        }

        return list;
    }

    private int findUpperClosest(int[] arr, int target) {
        int start = 0, end = arr.length - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (target <= arr[start]) {
            return start;
        }
        if (target <= arr[end]) {
            return end;
        }
        return end + 1;
    }

    private boolean isLeftCloser(int[] arr, int left, int right, int target){
        if(left < 0){
            return false;
        }
        if(right >= arr.length){
            return true;
        }
        return target - arr[left] <= arr[right] - target;
    }
}
```