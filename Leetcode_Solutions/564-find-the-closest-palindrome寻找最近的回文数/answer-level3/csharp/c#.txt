
```
public class Solution {
    public string NearestPalindromic(string n) {
        long result = Convert.ToInt64(n); 
        if (n.Length==1)
        {
            result--;
            return result.ToString();
        }
        //拆分字符串 双数位--》2个 单数位--》3个
        string shead = string.Empty;
        string smid = string.Empty;
        string stail = string.Empty;
        int mid = n.Length / 2;
        shead = n.Substring(0,mid);
        //是否是偶数
        bool isEven = false;
        if (n.Length % 2 == 0)
        {
            isEven = true;
            stail = n.Substring(mid,mid);
        }
        else
        {
            smid = n.Substring(mid,1);
            stail = n.Substring(mid + 1,mid);
        }

        string ReverseStr(string text)
        {
            char[] charArray = text.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }
        string Reverse(long i)
        {
            return ReverseStr(i.ToString());
        }
        
        string srehead = ReverseStr(shead);

        int ihead = Convert.ToInt32(shead);
        int irehead = Convert.ToInt32(srehead);
        int itail = Convert.ToInt32(stail);
        long imin = 0;
        long imax = 0;
        
        //本身是奇位回文数
        if ( srehead == stail && !isEven && smid!="0" && smid!="9")
        {
            smid = (Convert.ToInt16(smid) - 1).ToString();
            result = Convert.ToInt64(shead + smid + stail);
        }
        else
        {
            if (itail > irehead)
            {
                //irehead 为最小值
                imin = Convert.ToInt64(shead + smid + srehead) ;
                //奇位数 smid不是9 则直接操作smid 是9则会有溢出那么9--》0再按照偶位数计算
                if (!isEven && smid != "9")
                {
                    smid = (Convert.ToInt16(smid) + 1).ToString();
                    imax = Convert.ToInt64(shead+ smid + srehead) ;
                }
                else
                {
                    imax = ihead +1;
                    if (smid == "9")
                    {
                        smid = "0";
                    }
                    imax = Convert.ToInt64(imax.ToString() + smid + Reverse(imax)) ;
                }
            }
            else if (itail < irehead)
            {
                //irehead 为最大值
                imax = Convert.ToInt64(shead + smid + srehead) ;
                //奇位数 smid不是0 则直接操作smid 是0则会有溢出那么0--》9再按照偶位数计算
                if (!isEven && smid != "0")
                {
                    smid = (Convert.ToInt16(smid) - 1).ToString();
                    imin = Convert.ToInt64(shead+ smid + srehead) ;
                }
                else
                {
                    imin = ihead -1;
                    //降位
                    if (imin == 0 || (imin.ToString().Length < ihead.ToString().Length))
                    {
                        //e.g. 1001 999
                        imin = imax -2;
                    }
                    else
                    {
                        imin = Convert.ToInt64(imin.ToString() + smid + Reverse(imin)) ;
                    }
                }
            }
            else
            {
                if (!isEven)
                {
                    imin = Convert.ToInt16(smid) - 1;
                    imax = Convert.ToInt16(smid) + 1;
                    if (imin !=-1 && imax != 10)
                    {
                        imin = Convert.ToInt64(shead + imin.ToString() + stail);
                        imax = Convert.ToInt64(shead + imax.ToString() + stail);
                    }
                    else
                    {
                        if (imin == -1)
                        {
                            imax = Convert.ToInt64(shead + imax.ToString() + stail);
                            var temp = ihead -1;
                            //降位
                            if (temp == 0 || (temp.ToString().Length < ihead.ToString().Length))
                            {
                                //imin = Convert.ToInt64(shead + smid + srehead);
                                //e.g. 10001 9999
                                imin = result -2;
                            }
                            else
                            {
                                imin = Convert.ToInt64(temp.ToString() + "9" + Reverse(temp));
                            }
                        }
                        else
                        {
                            imin = Convert.ToInt64(shead + imin.ToString() + stail);
                            var temp = ihead + 1;
                            if (temp.ToString().Length > ihead.ToString().Length)
                            {
                                //imax = Convert.ToInt64(shead + smid + srehead);
                                imax = result + 2;
                            }
                            else
                            {
                                imax = Convert.ToInt64(temp.ToString() + "0" + Reverse(temp));
                            }
                        }
                    }

                }
                else
                {
                    var temp = ihead -1;
                    //降位
                    if (temp == 0 || (temp.ToString().Length < ihead.ToString().Length))
                    {
                        //e.g. 1001 999
                        imin = result -2;
                    }
                    else
                    {
                        imin = Convert.ToInt64(temp.ToString() + Reverse(temp));
                    }
                    temp = ihead + 1;
                    if (temp.ToString().Length > ihead.ToString().Length)
                    {
                        imax = result + 2;
                    }
                    else
                    {
                        imax = Convert.ToInt64(temp.ToString() + Reverse(temp));
                    }
                }
                
            }
            if ((imax -result) >= (result - imin))
            {
                result = imin;
            }
            else
            {
                result = imax;
            }
        }
        return result.ToString();
    }
}
```
