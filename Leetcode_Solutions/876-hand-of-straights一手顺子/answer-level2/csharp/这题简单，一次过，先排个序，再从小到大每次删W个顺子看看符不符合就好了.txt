 public  static bool IsNStraightHand(int[] hand, int W)
        {// 1 2 2 3 3 4 6 7 8     234678
            if (hand.Length % W != 0) return false;
            bool keyi = false;
            List<int> lst = hand.ToList();
            lst.Sort();

            AGAIN:
            List<int> record = new List<int>();
            int firstnum = lst[0];
            for (int i = 0; i < W;i++)
            {
                if(lst.Contains(firstnum+i)==false)
                {
                    return false;
                }
                record.Add(firstnum + i);
            }
            foreach (var num in record) lst.Remove(num);
            if(lst.Count==0)
            {
                return true;
            }
            else
            {
                goto AGAIN;
            }

            return keyi;
        }