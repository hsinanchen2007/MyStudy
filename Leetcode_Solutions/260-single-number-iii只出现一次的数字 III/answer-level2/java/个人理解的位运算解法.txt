class Solution {
    public int[] singleNumber(int[] nums) {
        int diff = 0;
        //将所有元素异或最终得到两个只出现一次的元素异或的结果
        for(int num : nums){
            diff ^= num;
        }
        /*1. 从异或的结果可知，当某位为1时表示两个元素在该位上不一样
        * 2. 通过异或取反加一再与原异或值取&，可以得到最右边两元素不相等的位
        *   （例两元素倒数第三的位置不一致，那么结果为0000100）
        * 3. 通过元素与该值取&，可以将为0和为1的值分离开来
        * 4. 最后得到这两个元素 
        */
        diff = diff & (~diff + 1);
        int[] result = new int[2];
        for(int num : nums){
            if((num & diff) == 0){
                result[0] ^= num;
            }else{
                result[1] ^= num;
            }
        }
        return result;
    }
}