public static bool ValidMountainArray(int[] A)
        {
            if (A.Length < 3) return false;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 1; i <= A.Length - 2; i++)
            {
                //对于每一个i A[0]<A[1]<...A[i]
                //对于每一个i A[i]>A[i+1]>...A[A.Length-1]
                dic.Add(i, A[i]);
                for (int j = 0; j < i; j++)
                {
                    if (A[j] >= A[j + 1])
                    {
                        dic.Remove(i);
                        return false;
                    }
                }
                for (int j = i; j < A.Length - 1; j++)
                {
                    if (A[j] < A[j + 1])
                    {
                        dic.Remove(i);
                        break;
                    }
                    if (A[j] == A[j + 1])
                    {
                        dic.Remove(i);
                        return false;
                    }
                }
                if (dic.Count == 1)
                    return true;
            }
            return false;
        }