import java.util.*;
class Solution {
    public List<Integer> sortArray(int[] nums) {
        QuickSort(nums, 0, nums.length - 1);
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; i++){
            list.add(nums[i]);
        }
        return list;
    }
    public void QuickSort(int[] arr, int start, int end){
        if (start > end){
            return;
        }
        int i = start;
        int j = end;
        int base = arr[start];
        while (i < j){
            while (i < j && arr[j] > base){
                j--;
            }
            arr[i] = arr[j];
            i++;
            while(i < j && arr[i] < base){
                i++;
            }
            arr[j] = arr[i];
            j --;
        }
        arr[i] = base;
        QuickSort(arr, start, i - 1);
        QuickSort(arr,j + 1, end);
    }
}