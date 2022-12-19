java 解决该问题
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) 
    {
        int num = 0;
        int[] arr = new int[100];
        for (int i = 0; i < dominoes.length; i++) 
        {
            int num1 = dominoes[i][0]*10 + dominoes[i][1];
            int num2 = dominoes[i][1]*10 + dominoes[i][0];
            if(num1 == num2)
            {
                num += arr[num1];
                arr[num1]++;
            }
            else
            {
                num += arr[num1];
                arr[num1]++;
                arr[num2]++;
            }
        }
        return num;
    }
}