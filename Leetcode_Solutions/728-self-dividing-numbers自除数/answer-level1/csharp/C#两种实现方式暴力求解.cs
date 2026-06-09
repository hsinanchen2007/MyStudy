```
    public IList<int> SelfDividingNumbers(int left, int right) {
            List<int> forreturn = new List<int>();
            for (int i = left; i <= right; i++)
            {
                if (i % 10 != 0)
                {
                    if (i / 10 > 0)
                    {
                        if (i / 10 % 10 != 0)
                        {
                            if (i / 100 > 0)
                            {
                                if (i / 100 % 10 != 0)
                                {
                                    if (i / 1000 > 0)
                                    {
                                        if ((i % (i % 10) == 0) && (i % (i / 10 % 10) == 0) && (i % (i / 100 % 10) == 0) && (i % (i / 1000) == 0))
                                        {
                                            forreturn.Add(i);
                                        }
                                    }
                                    else
                                    {
                                        if ((i % (i % 10) == 0) && (i % (i / 10 % 10) == 0) && (i % (i / 100) == 0))
                                        {
                                            forreturn.Add(i);
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if ((i % (i / 10) == 0) && (i % (i % 10) == 0))
                                {
                                    forreturn.Add(i);
                                }
                            }
                        }
                    }
                    else
                    {
                        forreturn.Add(i);
                    }
                }
            }
            return forreturn;
    }
```
```
    public IList<int> SelfDividingNumbers(int left, int right) 
    {
        List<int> forreturn = new List<int>();
        for (int i = left; i <= right; i++)
        {
            int remainder = 0;
            int m = i;
            bool flag = true;
            while (QuotientRemainder(m, out remainder) != 0)
            {
                m = m / 10;
                if (remainder == 0)
                {
                    break;
                }
                if (i % remainder != 0)
                {
                    flag = false;
                    break;
                }
                if (m / 10 == 0)
                {
                    if (i % m != 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if ((remainder == 0) || (flag == false))
            {
                continue;
            }
            forreturn.Add(i);
        }
        return forreturn;
    }
    public int QuotientRemainder(int num, out int remainder)
    {
        int quotient = num / 10;
        remainder = num % 10;
        return quotient;
    }
```
