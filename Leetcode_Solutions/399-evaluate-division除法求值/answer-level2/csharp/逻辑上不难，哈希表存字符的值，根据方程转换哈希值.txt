public static double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries)
        {
            Dictionary<string, string> dic = new Dictionary<string, string>();
            for (int i = 0; i < values.Length;i++)
            {
                if(dic.ContainsKey(equations[i][0])==false && dic.ContainsKey(equations[i][1])==false)
                {
                    dic.Add(equations[i][1], "1.0*"+equations[i][1]);
                    if(equations[i][0]!=equations[i][1])
                    {
                        dic.Add(equations[i][0], values[i].ToString()+"*"+equations[i][1]);
                    }
                }
                else if (dic.ContainsKey(equations[i][0]) && dic.ContainsKey(equations[i][1])==false)
                {
                    string[] temparr = dic[equations[i][0]].Split(new string[] { "*" }, StringSplitOptions.None);
                    dic.Add(equations[i][1],Convert.ToDouble(temparr[0]) / values[i]+"*"+temparr[1]);
                }
                else if (dic.ContainsKey(equations[i][1]) && dic.ContainsKey(equations[i][0]) == false)
                {
                    string[] temparr = dic[equations[i][1]].Split(new string[] { "*" }, StringSplitOptions.None);
                    dic.Add(equations[i][0], Convert.ToDouble(temparr[0]) * values[i] + "*" + temparr[1]);
                }
                else
                {
                    string _1st = dic[equations[i][0]];
                    string _2nd = dic[equations[i][1]];
                    string[] _1starr = _1st.Split(new string[] { "*" }, StringSplitOptions.None);
                    string[] _2ndarr = _2nd.Split(new string[] { "*" }, StringSplitOptions.None);
                    if(_1starr[1]!=_2ndarr[1])
                    {   //_1starr[1]=rate * _2ndarr[1]
                        double rate = values[i] * Convert.ToDouble(_2ndarr[0]) / Convert.ToDouble(_1starr[0]);
                        for (int j = 0; j < dic.Count; j++)
                        {
                            if (dic.ElementAt(j).Value.Contains(_1starr[1]))
                            {
                                string[] rawstrarr = dic.ElementAt(j).Value.Split(new string[] { "*" }, StringSplitOptions.None);
                                dic[dic.ElementAt(j).Key] = Convert.ToDouble(rawstrarr[0]) * rate + "*" + _2ndarr[1];
                            }
                        }
                    }
                }
            }
            double[] arr = new double[queries.Count];
            for (int i = 0; i < queries.Count;i++)
            {
                if(dic.ContainsKey(queries[i][0])==false||dic.ContainsKey(queries[i][1])==false)
                {
                    arr[i] = -1.0;
                }
                else
                {
                    string[] _1starr = dic[queries[i][0]].Split(new string[] { "*" }, StringSplitOptions.None);
                    string[] _2ndarr = dic[queries[i][1]].Split(new string[] { "*" }, StringSplitOptions.None);
                    if (_1starr[1] == _2ndarr[1])
                        arr[i] = Convert.ToDouble(_1starr[0]) / Convert.ToDouble(_2ndarr[0]);
                    else
                        arr[i] = -1.0;
                }
            }
            return arr;
        }