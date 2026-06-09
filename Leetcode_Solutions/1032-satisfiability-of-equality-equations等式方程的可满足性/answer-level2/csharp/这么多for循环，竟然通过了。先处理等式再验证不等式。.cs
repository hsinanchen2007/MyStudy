 HashSet<string> hsprocess = new HashSet<string>();//记录处理过的等式
            string[] strarr = new string[equations.Length];//用来存放等式相等的变量
            int arrindex = 0;
            for (int i = 0; i < strarr.Length; i++) strarr[i] = "";
            List<string> lststrbd = new List<string>();
            for (int i = 0; i < equations.Length;i++)
            {
                string sign = "d"; 
                string keyname1 = equations[i][0].ToString() + equations[i][3].ToString();
                string daozhiequ = equations[i][3].ToString() + equations[i][1].ToString() + equations[i][2].ToString() + equations[i][0].ToString();

                if (equations[i][1] == '!') sign = "bd";
                if (sign == "d")
                {
                    #region 等式处理进strarr,以便后续不等式的判断 
                    if (equations[i][0] == equations[i][3])//恒等式,不用管
                    {
                        hsprocess.Add(equations[i]);
                        continue;
                    }
                    if (hsprocess.Contains(equations[i]) == false) 
                    {
                        List<int> findkey = new List<int>(); List<int> sameword = new List<int>();
                        for (int j = 0; j < strarr.Length; j++)
                        {
                            if (strarr[j].Contains(equations[i][0]))
                            {
                                findkey.Add(j); sameword.Add(0);
                            }
                            else if (strarr[j].Contains(equations[i][3]))
                            {
                                findkey.Add(j); sameword.Add(3);
                            }
                            if (strarr[j] == "") break;
                        }
                        if (findkey.Count == 1) //a==b b==c 这种合并为abc 
                        {
                            if (strarr[findkey[0]].Contains(equations[i][3 - sameword[0]])==false) 
                                strarr[findkey[0]] += equations[i][3 - sameword[0]];
                        }
                        else if (findkey.Count == 2) //a==b c==d a==c 这种合并相等组为abcd
                        {
                            strarr[findkey[0]] += strarr[findkey[1]];
                            strarr[findkey[1]] = findkey[1].ToString();
                        }
                        else if (findkey.Count == 0) //没有处理过,直接加
                        {
                            strarr[arrindex] = keyname1;
                            arrindex++;
                        }
                        hsprocess.Add(equations[i]);
                        hsprocess.Add(daozhiequ);//a==b b==a这种倒过来写的不用处理了
                    }
                    #endregion
                }
                else
                {
                    lststrbd.Add(equations[i]);
                }
            }
           
            // 判断不等式是否成立
            for (int i = 0; i < lststrbd.Count; i++)
            {
                char word1 = lststrbd[i][0];
                char word2 = lststrbd[i][3];
                if (word1 == word2) return false;
                for(int j=0;j<strarr.Length;j++)
                {
                    if(strarr[j].Contains(word1) && strarr[j].Contains(word2))
                    {
                        return false;
                    }
                    if (strarr[j] == "") break;
                }
            }
            return true;

