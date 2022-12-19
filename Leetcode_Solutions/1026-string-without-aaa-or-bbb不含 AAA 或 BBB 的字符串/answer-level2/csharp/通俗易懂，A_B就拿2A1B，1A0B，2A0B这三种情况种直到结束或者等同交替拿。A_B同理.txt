 public static string StrWithout3a3b(int A, int B)
        {
            string str = "";
            HERE:
            if (A == B)
            {
                for (int i = 0; i < A + B; i++) //ABAB
                {
                    if (i % 2 == 0)
                        str += "a";
                    else
                        str += "b";
                }
            }
            else if (A > B)
            {
                if(B==0 && A==1)
                {
                    str += "a";
                    return str;
                }
                else if(B==0 && A==2)
                {
                    str += "aa";
                    return str;
                }
                else
                {
                    str += "aab";
                    A = A - 2;
                    B = B - 1;
                    goto HERE;
                }
            }
            else if (A < B)
            {
                if (A == 0 && B == 1)
                {
                    str += "b";
                    return str;
                }
                else if (A == 0 && B == 2)
                {
                    str += "bb";
                    return str;
                }
                else
                {
                    str += "bba";
                    A = A - 1;
                    B = B - 2;
                    goto HERE;
                }
            }

            return str;
        }