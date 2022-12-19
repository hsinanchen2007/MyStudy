```
        public int MyAtoi2(string str)
        {
            Dictionary<string, List<string>> table = new Dictionary<string, List<string>>();
            table.Add("start",new List<string> { "start", "signed", "in_number", "end" });
            table.Add("signed", new List<string> { "end", "end", "in_number", "end" });
            table.Add("in_number", new List<string> { "end", "end", "in_number", "end" });
            table.Add("end", new List<string> { "end", "end", "end", "end" });
            int sign = 1;
            double ans = 0;
            string state = "start";
            for(int i = 0; i < str.Length; i++)
            {
                state = table[state][Get_col(str[i])];
               
                if (state.Equals("in_number"))
                {
                    ans = ans * 10 + str[i] - '0';
                   
                    if (sign == 1)
                    {
                        ans = Math.Min(ans, int.MaxValue);
                    }
                    else
                    { 
                        ans = Math.Min(ans, -(long)int.MinValue);
                        
                    }
                }
                else if (state.Equals("signed"))
                    sign = str[i] == '+' ? 1 : -1;
            }
            return (int)ans*sign;
               
        }

        public int Get_col(char c)
        {
            if (c == ' ')
                return 0;
            else if (c == '+' || c == '-')
                return 1;
            else if (c >= '0' && c <= '9')
                return 2;
            else
                return 3;
        }
```
