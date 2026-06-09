```
public static int Calculate(string s)
        {                   //8+7*6-5/4+3-2*1/1
            int val = 0;    //8+42-1+3-2

            string[] jia = s.Split(new string[] { "+" }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < jia.Length; i++)
            {
                string[] jian = jia[i].Split(new string[] { "-" }, StringSplitOptions.RemoveEmptyEntries);
                int[] jianint = new int[jian.Length];
                for (int j = 0; j < jianint.Length; j++)
                {
                    jianint[j] = GeberateJianj(jian[j]);
                }
                int jianval = jianint.Aggregate((a, b) => a - b);

                val += jianval;
            }

            return val;
        }

        private static int GeberateJianj(string exp)
        {
            if(exp.Contains("*")==false && exp.Contains("/")==false)
            {
                return Convert.ToInt32(exp);
            }
            string[] num = new string[2]{"",""}; 
            string lastoper = "";
            for(int i=0;i<exp.Length;i++)
            {//2*1/1
                #region MyRegion
                if (exp[i] == '*')
                {
                    if (lastoper == "")
                        lastoper = "*";
                    else
                    {
                        if (lastoper == "*")
                        {
                            num[0] = (Convert.ToInt32(num[0]) * Convert.ToInt32(num[1])).ToString();
                            num[1] = "";
                            lastoper = "*";
                        }
                        else
                        {
                            num[0] = (Convert.ToInt32(num[0]) / Convert.ToInt32(num[1])).ToString();
                            num[1] = "";
                            lastoper = "*";
                        }
                    }
                }
                else if (exp[i] == '/')
                {
                    if (lastoper == "")
                        lastoper = "/";
                    else
                    {
                        if (lastoper == "*")
                        {
                            num[0] = (Convert.ToInt32(num[0]) * Convert.ToInt32(num[1])).ToString();
                            num[1] = "";
                            lastoper = "/";
                        }
                        else
                        {
                            num[0] = (Convert.ToInt32(num[0]) / Convert.ToInt32(num[1])).ToString();
                            num[1] = "";
                            lastoper = "/";
                        }
                    }
                }
                else//number
                {
                    if (lastoper == "")
                        num[0] += exp[i];
                    else
                        num[1] += exp[i];
                } 
                #endregion
            }

            if (lastoper == "*")
            {
                return  (Convert.ToInt32(num[0]) * Convert.ToInt32(num[1]));
            }
            else
            {
                return (Convert.ToInt32(num[0]) / Convert.ToInt32(num[1]));
            }

        }