```
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = binarySearch(numbers, target);
        int[] ans = new int[2];
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                ans[0] = left + 1;
                ans[1] = right + 1;
                return ans;
            }else if(numbers[left] + numbers[right] < target){
                left += 1;               
            }else if(numbers[left] + numbers[right] > target){
                right -= 1;
            }
        }
        return ans;
    }
    
    public int binarySearch(int[] numbers, int target){
        int l = 0;
        int r = numbers.length - 1;
        if (numbers[r] < target)
            return r;
        int mid = (l + r + 1) / 2;
        while(! (numbers[mid] < target && numbers[mid + 1] > target)){
            mid = (l + r + 1) / 2;
            if(numbers[mid] == target){
                return mid + 1;
            }else if(numbers[mid] < target){
                l = mid + 1;
            }else if(numbers[mid] > target){
                r = mid - 1;
            }
        }
        return mid + 1;
    }
}
```
