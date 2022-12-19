if (num == 0) return false;
            List<int> lst = new List<int>();
            int limit = num / 2;
            for (int i = 1; i <= limit; i++)
            {
                if (num % i == 0)
                {
                    if (lst.Contains(i) == false)  lst.Add(i);
                    if(i>1)
                    {
                        limit = num / i;
                        if (lst.Contains(limit)==false)
                            lst.Add(limit);
                    }
                }
            }

            if (lst.Sum() == num)
                return true;
            else
                return false;