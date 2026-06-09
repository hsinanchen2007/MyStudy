```
package ZJM_66_加一;

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {1,2,3};
        int[] nums2 = {4,3,2,1};
        int[] nums3 = {9,8,7,6,5,4,3,2,1,0};
        int[] nums4 = {9};
        int[] nums5 = {9,9};
        int[] nums6 = {8,9,9,9};

        Solution solution = new Solution();
        int[] result1 = solution.plusOne(nums1);
        int[] result2 = solution.plusOne(nums2);
        int[] result3 = solution.plusOne(nums3);
        int[] result4 = solution.plusOne(nums4);
        int[] result5 = solution.plusOne(nums5);
        int[] result6 = solution.plusOne(nums6);

        for(int i=0;i<result1.length;i++){
            System.out.print(result1[i]+" ");
        }

        System.out.println();

        for(int i=0;i<result2.length;i++){
            System.out.print(result2[i]+" ");
        }

        System.out.println();

        for(int i=0;i<result3.length;i++){
            System.out.print(result3[i]+" ");
        }

        System.out.println();

        for(int i=0;i<result4.length;i++){
            System.out.print(result4[i]+" ");
        }

        System.out.println();

        for(int i=0;i<result5.length;i++){
            System.out.print(result5[i]+" ");
        }

        System.out.println();

        for(int i=0;i<result6.length;i++){
            System.out.print(result6[i]+" ");
        }
    }
}

class Solution {
    public int[] plusOne(int[] digits) {
//        if(digits[0]==0){
//            digits[0] += 1;
//            return digits;
//        }
//
//        int temp=0;
//
//        for(int i=0;i<digits.length;i++){
//            temp*=10;
//            temp+=digits[i];
//        }
//
//        temp+=1;
//        System.out.println(temp);
//        String templen = ""+temp;
//
//        int[] temparray = new int[templen.length()];
//
//        for(int i=temparray.length-1;i>=0;i--){
//            temparray[i]=temp%10;
//            temp/=10;
//        }
//
//        return temparray;
        if(digits[0]==0){
            digits[0] += 1;
            return digits;
        }

        for(int i=digits.length-1;i>=0;i--){
            if(digits[i]+1!=10){
                digits[i]+=1;
                return digits;
            }else {
                digits[i]=0;
            }
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;

        return digits;
    }
}

/**
 * 本题我最初的思路是将数组先转化为数字，然后数字自增1，再将数字转化为数组，但这种方法会有一些特殊情况
 * 比如说{9,8,7,6,5,4,3,2,1,0}这个数组转化为int会溢出，得到的就是错误的答案
 * 所以本题应该换个思路，将数组的最后一个元素+1，如果得到的10，就对其前一位+1，需要注意处理的是进位的情况，
 * 数组{9}变为{1,0}
 */

```
