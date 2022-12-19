List<char> lst = new List<char>();
            for(int i=0;i<str.Length;i++)
            {
                int asci = (int)str[i];
                if ((asci >= 65 && asci <= 90))
                {
                    string newchar = Encoding.ASCII.GetString(new byte[] { Convert.ToByte(asci + 32) });
                    lst.Add(newchar[0]);
                }
                else
                     lst.Add(str[i]);
            }
            return string.Join("", lst);