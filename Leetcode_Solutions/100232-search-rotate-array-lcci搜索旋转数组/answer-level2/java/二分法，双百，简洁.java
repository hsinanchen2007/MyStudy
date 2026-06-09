```
class Solution {
    public int search(int[] arr, int target) {
        int left = 0 ;
        int right = arr.length-1;
        while(left <= right)
        {
            if(left != right && arr[left] == arr[right] ){//先排除右边跟第一个数相等的数
                right--;
                continue;
            }
            int mid = (right+left)/2;
            if(target == arr[mid] && (mid == 0 || target != arr[mid-1]))
                return mid;
            if(arr[left] <= arr[mid] ){//左边有序
                if(target >= arr[left] && target <= arr[mid])
                    right = mid;
                else
                    left = mid +1;
            }
            else{
                if(target >= arr[mid] && target <= arr[right])
                    left = mid;
                else
                    right =mid - 1;
            }
        }
        return -1;
    }
}
```
