public static string SolveEquation(string equation)
        {
            double jiedb = 1.0;
            equation = equation.Replace(" ", "");
            string[] strarr = equation.Split(new string[] { "=" }, StringSplitOptions.None);
            string qianmian = strarr[0];
            string houmian = strarr[1];
            if (houmian[0] != '+' && houmian[0] != '-')
            {
                houmian = strarr[1].Insert(0, "+");
            }
            char[] houmianchr = houmian.ToCharArray();
            for (int i = 0; i < houmianchr.Length; i++)
            {
                if (houmianchr[i] == '-')
                    houmianchr[i] = '+';
                else if (houmianchr[i] == '+')
                    houmianchr[i] = '-';
            }
            houmian = string.Join("", houmianchr);
            string equation2 = qianmian + houmian;
            equation2 = equation2.Replace("-", "+-");
            string[] strarr2 = equation2.Split(new string[] { "+" }, StringSplitOptions.None);
            double A = 0, B = 0;//Ax+B=0
            for (int i = 0; i < strarr2.Length; i++)
            {
                if (strarr2[i].Trim() != string.Empty)
                {
                    if (strarr2[i].Contains("x"))
                    {
                        int xishu = 0;
                        if (strarr2[i] == "x")  xishu = 1;
                        else if (strarr2[i] == "-x")  xishu = -1;
                        else
                        {
                            xishu = Convert.ToInt32(strarr2[i].Substring(0,strarr2[i].Length-1));
                        }
                        A += xishu;
                    }
                    else
                    {
                        B += Convert.ToInt32(strarr2[i]);
                    }
                }
            }
            if (A == 0 && B == 0) return "Infinite solutions";
            if (A == 0 && B != 0) return "No solution";
            jiedb = (0 - B) / A;
            int jieint = Convert.ToInt32(jiedb);
            return "x=" + jieint;
        }

