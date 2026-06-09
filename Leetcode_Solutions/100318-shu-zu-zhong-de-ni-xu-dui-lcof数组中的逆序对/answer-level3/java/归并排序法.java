### 解题思路
只需在进行归并排序的时候设置一个count，计算逆序对
只在arr[i] > arr[j]的时候添加count += (mid+1-i)

### 代码

```java
/**
 * 利用归并排序的思路 只不过在merge的时候加上一个逆序对
 */
class Solution {

    int count;
    public int reversePairs(int[] nums) {
        mergeSort(nums, 0, nums.length-1);
        return count;
    }

    // 归并排序  对arr[l:r]进行归并排序
    public void mergeSort(int[] arr, int l, int r){
        if(r - l < 1){
            return;
        }
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }

    // merge操作 对两个排好序的数组进行合并操作  对arr[l:r]进行排序  arr[l:mid]和arr[mid+1:r]sorted
    private void merge(int[] arr, int l, int mid, int r){
        // 设置一个缓存数组
        int n = r-l+1;  //缓冲数组的大小
        int[] tmpArr = new int[n];
        int i=l, j=mid+1, k=0;  //i指示左侧数组，j指示右侧数组，k指示缓存数组
        while(k < n){
            if(i>mid){
                tmpArr[k++] = arr[j++];
            }
            else if(j>r){
                tmpArr[k++] = arr[i++];
            }
            else{
                if(arr[i] <= arr[j]){
                    tmpArr[k++] = arr[i++];
                }else {
                    count += (mid+1-i);
                    tmpArr[k++] = arr[j++];
                }
            }
        }

        for(int t=0; t<n; t++){
            arr[t+l] = tmpArr[t];
        }
    }
}
```