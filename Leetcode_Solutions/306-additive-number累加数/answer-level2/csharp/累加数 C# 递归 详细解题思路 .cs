               public bool IsAdditiveNumber(string num)
        {
            if (num.Length < 3) return false;
            string lts, rts, ets;
            //先判断前三数是否是累加数 再开始递归
            for (int i = 1; i <= num.Length - 2; i++)
            {
                lts = num.Substring(0, i);                                          //第一个数
                if (lts[0] == '0' && lts.Length > 1) continue;                      //tirps1:如果开始为0,跳过
                for (int j = 1; j <= num.Length - i; j++)
                {
                    rts = num.Substring(i, j);                                      //第二个数
                    if (rts[0] == '0' && rts.Length > 1) continue;                  //tirps1
                    for (int k = j; k <= num.Length - i - j; k++)
                    {
                        //如果K的值(此处代表的num长度)小余I或者J 则跳过 B:加法的等余数不能比最大值的长度小
                        if (k < i || k < j) continue;
                        //判断K的值是否大于I或J的最大值大2 如果是则跳过 B:因为加法的等余数在最大值的长度上加1 如果超过则等式不成立
                        if (k > ((i > j) ? i : j) + 1) break;
                        ets = num.Substring(i + j, k);                              //第三个数
                        if (ets[0] == '0' && ets.Length > 1) continue;              //tirps1
                        if (long.Parse(lts) + long.Parse(rts) == long.Parse(ets))
                        //转换相加时 如果num数过大 则会导致溢出 目前暂时没想到解决方法
                        {
                            //第一次判断 如果加法里 值的长度相加相等 则成立 
                            if (lts.Length + rts.Length + ets.Length == num.Length) return true;
                            //开始递归 传入num(移除第一个数str),第二个数str,第三个数str
                            //其中 传入的rts代表递归函数中的第一个数, ets代表第二个数 递归则判断是否等于第三个数
                            else if (IsAddBack(num.Substring(lts.Length, num.Length - lts.Length), rts, ets)) return true;
                        }
                    }
                }
            }
            return false;
        }

        //递归函数
        public bool IsAddBack(string num, string lts, string rts)
        {
            string ets;
            int lt = int.Parse(lts), rt = int.Parse(rts);
            for (int i = 1; i <= num.Length - (lts.Length + rts.Length); i++)
            {
                if (i < lts.Length || i < rts.Length) continue;
                if (i > ((lts.Length > rts.Length) ? lts.Length : rts.Length) + 1) break;
                ets = num.Substring(lts.Length + rts.Length, i);
                if (ets[0] == '0' || (ets.Length < rts.Length)) continue;
                if (lt + rt == int.Parse(ets))
                {
                    if (lts.Length + rts.Length + ets.Length == num.Length) return true;
                    else return IsAddBack(num.Substring(lts.Length, num.Length - lts.Length), rts, ets);
                }
            }
            return false;
        }
        //提交效果 内存消耗20左右 时间 平均 80 90ms 看字符长度