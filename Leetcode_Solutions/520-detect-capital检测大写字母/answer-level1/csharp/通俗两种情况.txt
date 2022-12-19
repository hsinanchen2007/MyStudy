public static bool DetectCapitalUse(string word)
        {
            if (word.Length <= 1) return true;
            char _1stchr = word[0];
            int ascii = 0;// (int)_1stchr  也可以获取ascii码
            byte[] array = Encoding.ASCII.GetBytes(new char[] { _1stchr });
            ascii = (int)(array[0]);
            //string test1 = ((char)65).ToString();
            //string test2 = Encoding.ASCII.GetString(new byte[] { 65,66});
            if(ascii>=65 && ascii<=90)//首字母大写,剩下全部大写或者全部小写
            {
                HashSet<string> hs = new HashSet<string>();
                for(int i=1;i<word.Length;i++)
                {
                    int val = (int)word[i];
                    if(val>=65 && val<=90)
                    {
                        hs.Add("DA");
                    }
                    else if (val >= 97 && val <= 122)
                    {
                        hs.Add("xiao");
                    }
                    if (hs.Count == 2) return false;
                }
            }
            else if (ascii >= 97 && ascii <= 122)//首字母小写,剩下全部小写
            {
                for(int i=1;i<word.Length;i++)
                {
                    if ((int)word[i] <= 90)
                        return false;
                }
            }
            return true;
        }