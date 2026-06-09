public static int LengthOfLastWord(string s)
        {
            int count = 0;
            bool meet = false;
            for (int i = s.Length - 1; i >= 0; i--)
            {
                if (s[i] != ' ')
                {
                    count++;
                    meet = true;
                }
                else
                {
                    if (meet)
                        break;
                }
            }
            return count;
        }