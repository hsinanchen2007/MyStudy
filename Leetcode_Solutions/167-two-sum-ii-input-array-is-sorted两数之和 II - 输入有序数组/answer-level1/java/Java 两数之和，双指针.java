有序就考虑双指针，朝靠近target的方向移动

public static int[] twoSum(int[] numbers, int target) {
        int left =0;
        int right = numbers.length-1;
        while(left<right){
            if (numbers[left]+numbers[right]==target){
                return new int[]{left+1,right+1};
            }else if (numbers[left]+numbers[right]<target){
                left++;
            }else{
                right--;
            }
        }
        return null;
    }