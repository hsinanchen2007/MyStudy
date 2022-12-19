1.
public class Solution {
    public int RomanToInt(string s) {
                    s = s.Replace("IV", "IIII").Replace("IX", "VIIII").Replace("XL", "XXXX").
                Replace("XC", "LXXXX").Replace("CD", "CCCC").Replace("CM", "DCCCC");
            int num = 0;
            foreach (char c in s)
            {
                switch(c)
                {
                    case 'I':
                        num += 1;
                        break;
                    case 'V':
                        num += 5;
                        break;
                    case 'X':
                        num += 10;
                        break;
                    case 'L':
                        num += 50;
                        break;
                    case 'C':
                        num += 100;
                        break;
                    case 'D':
                        num += 500;
                        break;
                    case 'M':
                        num += 1000;
                        break;
                    default:
                        break;
                }
            }

            return num;
    }
}


2.
public class Solution {
    public int RomanToInt(string s) {
        int result = 0;
            for (int i = 0; i < s.Length; i++)
            {
                int current = getValue(s[i]);
                if (i == s.Length - 1 || current >= getValue(s[i + 1]))
                {
                    result += current;
                }
                else
                {
                    result -= current;
                }
            }
            return result;
    }
     public int getValue(char c)
        {

            switch (c)
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
                    throw new Exception();
            }
        }
}


3.
public class Solution {
    public int RomanToInt(string s) {
    int num = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'I')
                    num += 1;
                else if (s[i] == 'V')
                    num += 5;
                else if (s[i] == 'X')
                    num += 10;
                else if (s[i] == 'L')
                    num += 50;
                else if (s[i] == 'C')
                    num += 100;
                else if (s[i] == 'D')
                    num += 500;
                else if (s[i] == 'M')
                    num += 1000;
            }
            for (int i = 0; i < s.Length - 1; i++)
            {
                string s1 = s.Substring(i, 2);
                if (s1.Equals("IV"))
                    num -= 2;
                else if (s1.Equals("IX"))
                    num -= 2;
                else if (s1.Equals("XL"))
                    num -= 20;
                else if (s1.Equals("XC"))
                    num -= 20;
                else if (s1.Equals("CD"))
                    num -= 200;
                else if (s1.Equals("CM"))
                    num -= 200;
            }
            return num;

    }
}


4.
public class Solution {
    public int RomanToInt(string s) {
string[] roman = { "IV", "IX", "XL", "XC", "CD", "CM", "I", "V", "X", "L", "C", "D", "M" };
            int[] nums = { 4, 9, 40, 90, 400, 900, 1, 5, 10, 50, 100, 500, 1000 };
            int num = 0;
            while (s.Length > 0)
            {
                for (int i = 0; i < roman.Length; i++)
                {
                    if (s.StartsWith(roman[i]))
                    {
                        num += nums[i];
                        s = s.Substring(roman[i].Length);
                        break;
                    }
                }
            }
            return num;
    }
}


5.
public class Solution {
    public int RomanToInt(string s) {
                    Dictionary<string, int> map = new Dictionary<string, int>();
            map.Add("I", 1);
            map.Add("IV", 4);
            map.Add("V", 5);
            map.Add("IX", 9);
            map.Add("X", 10);
            map.Add("XL", 40);
            map.Add("L", 50);
            map.Add("XC", 90);
            map.Add("C", 100);
            map.Add("CD", 400);
            map.Add("D", 500);
            map.Add("CM", 900);
            map.Add("M", 1000);

            int ans = 0;
            for (int i = 0; i < s.Length;)
            {
                if (i + 1 < s.Length && map.ContainsKey(s.Substring(i, 2)))
                {
                    int num;
                    map.TryGetValue(s.Substring(i, 2), out num);
                    ans += num;
                    i += 2;
                }
                else
                {
                    int num;
                    map.TryGetValue(s.Substring(i, 1), out num);
                    ans += num;
                    i++;
                }
            }
            return ans;
    }
}


6.
//6
public class Solution {
          public int RomanToInt(string s)
        {
            Dictionary<char, int> roman = new Dictionary<char, int>();
            roman.Add('M', 1000);
            roman.Add('D', 500);
            roman.Add('C', 100);
            roman.Add('L', 50);
            roman.Add('X', 10);
            roman.Add('V', 5);
            roman.Add('I', 1);
            int res = 0, pre = 0;
            foreach (char c in s.ToCharArray())
            {
                int cur;
                roman.TryGetValue(c,out cur);
                res += cur > pre ? cur - 2 * pre : cur;
                pre = cur;
            }
            return res;
        }
}