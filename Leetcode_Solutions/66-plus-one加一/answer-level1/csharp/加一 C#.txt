public class Solution {
    public int[] PlusOne(int[] digits) {
        for (int i = digits.Length - 1; i >= 0; i--)
            {
                digits[i]++;
                digits[i] = digits[i] % 10;
                if (digits[i] != 0)
                {
                    return digits;
                }
            }

            if (digits[0] == 0)
            {
                digits = new int[digits.Length + 1];
                digits[0] = 1;
            }

            return digits;
    }    
}