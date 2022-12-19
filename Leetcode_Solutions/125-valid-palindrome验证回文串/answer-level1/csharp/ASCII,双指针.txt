 int i = 0, j = s.Length - 1;
            while(i<j)
            {
                int asci = (int)s[i];
                int ascj = (int)s[j];
                if((asci>=48 && asci<=57)||(asci>=97 && asci<=122)||(asci>=65 && asci<=90))
                {
                    if ((ascj >= 48 && ascj <= 57) || (ascj >= 97 && ascj <= 122) || (ascj >= 65 && ascj <= 90))
                    {
                        if(s[i]!=s[j]&&s[i].ToString().ToLower()!=s[j].ToString().ToLower())
                        {
                            return false;
                        }
                        else
                        {
                            i++; j--;
                        }
                    }
                    else
                    {
                        j--;
                    }
                }
                else
                {
                    i++;
                }
            }
            return true;