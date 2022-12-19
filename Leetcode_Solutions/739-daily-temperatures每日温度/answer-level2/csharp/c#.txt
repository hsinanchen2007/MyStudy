public class Solution {
    public int[] DailyTemperatures(int[] T) {
        int length = T.Length;
        int[] result = new int[length];

        for(int i = length-2;i>=0;i--)
        {
            for(int j = i+1;j<length;j+=result[j])
            {
                if(T[i]<T[j])
                {
                    result[i]=j-i;
                    break;
                }
                else if(result[j]==0)
                {
                    result[i]=0;
                    break;
                }
            }
        }
       return result;
     
    }
}
