public class MedianFinder
    {
        List<int> lst;
        int max = 0;
        /** initialize your data structure here. */
        public MedianFinder()
        {
            lst = new List<int>();
        }

        public void AddNum(int num)
        {
            if (lst.Count == 0)
            {
                lst.Add(num);
                max = num;
            }
            else
            {
                if (num>max)
                {
                    lst.Add(num);
                    max = num;
                }
                else
                {
                    for (int i = 0; i < lst.Count; i++)
                    {
                        if (num <= lst[i])
                        {
                            lst.Insert(i, num);
                            break;
                        }
                    }
                }
            }
        }

        public double FindMedian()
        {
            if(lst.Count%2==1)
            {
                return lst[lst.Count / 2];
            }
            else
            {
                int left = lst[lst.Count / 2-1];
                int right = lst[lst.Count / 2];
                return (left + right) * 1.0 / 2;
            }
        }
    }