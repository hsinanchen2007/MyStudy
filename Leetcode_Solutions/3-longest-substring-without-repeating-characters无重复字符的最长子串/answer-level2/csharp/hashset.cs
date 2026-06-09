
private static  int MaxNoRepeatStrLen(string str)
        {
            int result = 0;
            HashSet<char> hs = new HashSet<char>();

            for(int i = 0; i < str.Length; i++)
            {
                hs.Add(str[i]);
                for(int j = i + i; j < str.Length; j++)
                {
                    if (!hs.Add(str[j]))
                    {
                        result = Math.Max(hs.Count, result);
                        hs.Clear();
                        continue;
                    }
                }
            }

            return result;

        }