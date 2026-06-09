class Solution {
    public int minArray(int[] numbers) {
        int low = 0;
        int high = numbers.length -1;
        int mid = 0;
        while(low<high){
            mid = (low + high)/2;
            System.out.println(mid+"|"+low+"|"+high);
            if(numbers[mid]>numbers[high]){  // 左半段
                low=mid+1;
            }else if(numbers[mid]<numbers[high]){ // 右半段
                high=mid;
            }else {
                high--;
            }
        }
        return numbers[low];
    }
}