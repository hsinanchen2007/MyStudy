看起来比较长 主要是想着能不新建数组就不建了
class Solution {
    public int[] plusOne(int[] digits) {
        int length = digits.length-1;
        int flag = 1;
        for(int i=length; i>-1; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i] += flag;
                flag = 0;
                break; 
            }
        }
        if(flag == 1){
            int[] arr = new int[length+2];
            arr[0] = 1;
            for(int j=1,i=0; j<arr.length; j++){
                arr[j] = digits[i++];
            }
            return arr;
        }else{
            return digits;
        }
    }
}