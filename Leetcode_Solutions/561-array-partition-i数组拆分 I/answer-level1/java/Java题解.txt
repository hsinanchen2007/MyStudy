//思路：先进行排序，然后遍历数组，从最小的开始隔一位取值相加。
//原因：根据题目中的意思，最小值是肯定会用上，所以把对半取的最小值都加起来，就是结果

class Solution {
    public int arrayPairSum(int[] ints){
        int len = ints.length;
        if (len % 2 == 0){
            Arrays.sort(ints);
            int sum = 0;
            for (int i = 0; i < len; i++) {
                sum += ints[i];
                i++;
            }
            return sum;
        }
        return 0;
    }
}