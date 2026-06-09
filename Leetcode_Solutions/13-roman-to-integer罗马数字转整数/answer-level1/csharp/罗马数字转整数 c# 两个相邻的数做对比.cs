public class Solution {
    public int RomanToInt(string s) {
        if (s.Length < 2)
            {
                return changeToInt(s[0]);
            }

            var sum = 0;
            var i = 0;
            for (; i < s.Length - 1; i++)
            {
                // compare first and second, if previous >= later just add previous one
                if (changeToInt(s[i]) >= changeToInt(s[i+1]))
                {
                    sum += changeToInt(s[i]);
                }
                else
                {
                    // if previous < later  add "later one - previous one"
                    sum += changeToInt(s[i+1]) - changeToInt(s[i]);
                    i++;
                }
            }

            if (i == s.Length -1) // deal with last number
            {
                sum += changeToInt(s[i]);
            }

            return sum;
    }
    
    public int changeToInt(char a)
        {
            switch (a)
            {
                case 'I':
                    return 1;
                case 'V':
                    return 5;
                case 'X':
                    return 10;
                case 'L':
                    return 50;
                case 'C':
                    return 100;
                case 'D':
                    return 500;
                case 'M':
                    return 1000;
                default:
                    return 0;
            }
        }
}