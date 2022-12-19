```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        // 基于快排分治思想
        // 找到 中轴点为 k - 1 的数。下标为 0 ~ k - 1 即为 最小 k 个数
        partition(arr, 0, arr.length - 1, k - 1);
        return Arrays.copyOf(arr, k);
    }
    
    public void partition(int[] arr, int left, int right, int k){
        if(left > right) return;
        int i = left - 1;
        for(int j = left; j < right; j++){
            if(arr[j] <= arr[right]){
                int temp = arr[j];
                arr[j] = arr[++i];
                arr[i] = temp;
            }
        }            
        int tmp = arr[right];
        arr[right] = arr[++i];
        arr[i] = tmp;
        
        if(i == k) 
            return;
        // 递归：若 k > i，则继续在右边寻找 k， 反之，在左边找
        else if(i < k){
            partition(arr, i + 1, right, k);
        }else{
            partition(arr, left, i - 1, k);
        }
    }
}
```
