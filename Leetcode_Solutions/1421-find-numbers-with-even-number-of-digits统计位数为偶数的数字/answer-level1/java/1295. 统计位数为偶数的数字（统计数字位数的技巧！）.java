class Solution {
    /**
        技巧：使用字符串转换来统计数字的位数！！！
    **/
    public int findNumbers(int[] nums) {
        int count = 0;
        for(int num : nums){
            if(String.valueOf(num).length()%2 == 0)
                count += 1;
        }
        return count;
    }
}