~~~C#
public int RomanToInt(string s)
        {
            int sum = 0;
            int backNum = 0; //记录上一个数字
            if (s.Equals("")||s==null)
            {
                return 0;
            }
            for (int i = 0; i < s.Length; i++)
            {
                switch (s[i])
                {
                    case 'I':
                        sum = sum + 1;
                        backNum = 1;
                        break;
                    case 'V':
                        sum = backNum < 5 ? sum = sum - backNum + 5 - backNum : sum = sum + 5;
                        backNum = 5;
                        break;
                    case 'X':
                        sum = backNum < 10 ? sum = sum - backNum + 10 - backNum : sum = sum + 10;
                        backNum = 10;
                        break;
                    case 'L':
                        sum = backNum < 50 ? sum = sum - backNum + 50 - backNum : sum = sum + 50;
                        backNum = 50;
                        break;
                    case 'C':
                        sum = backNum < 100 ? sum = sum - backNum + 100 - backNum : sum = sum + 100;
                        backNum = 100;
                        break;
                    case 'D':
                        sum = backNum < 500 ? sum = sum - backNum + 500 - backNum : sum = sum + 500;
                        backNum = 500;
                        break;
                    case 'M':
                        sum = backNum < 1000 ? sum = sum - backNum + 1000 - backNum : sum = sum + 1000;
                        backNum = 1000;
                        break;
                }

            }
            return sum;
        }
~~~
