 string forreturn = "Neither";
            if(IP.Contains("."))
            {
                string[] arrv4 = IP.Split(new string[] { "." }, StringSplitOptions.RemoveEmptyEntries);
                if (arrv4.Length == 4 && IP.Count(p => p == '.') == 3)
                {
                    bool res = true;
                    for(int i=0;i<arrv4.Length;i++)
                    {
                        int result = -1;
                        if (int.TryParse(arrv4[i],out result))
                        {
                            if (result < 0||result > 255 ||arrv4[i].StartsWith("-"))
                            {
                                res = false;
                                break;
                            }
                            else if(arrv4[i][0]=='0' && arrv4[i].Length>1)
                            {
                                res = false;
                                break;
                            }
                        }
                        else
                        {
                            res = false;
                            break;
                        }
                    }
                    if (res) forreturn = "IPv4";
                }
            }
            else if(IP.Contains(":"))
            {
                string[] arrv6 = IP.Split(new string[] { ":" }, StringSplitOptions.RemoveEmptyEntries);
                if (arrv6.Length == 8 && IP.Count(p=>p==':')==7)
                {
                    bool res = true;
                    for (int i = 0; i < arrv6.Length; i++)
                    {
                        if (arrv6[i].Length>4)
                        {
                            res = false;
                            break;
                        }
                        for(int j=0;j<arrv6[i].Length;j++)
                        {
                            if("0123456789abcdefABCDEF".IndexOf(arrv6[i][j])<0)
                            {
                                res = false;
                                break;
                            }
                        }
                        if (res == false) break;
                    }
                    if (res) forreturn = "IPv6";
                }
            }
            return forreturn;