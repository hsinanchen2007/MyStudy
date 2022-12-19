if (A.Length < 3) return false;
            if (A[0] >= A[1]) return false;
            int highindex = -1;
            for (int i = 0; i < A.Length -1; i++)
            {
                if (A[i] == A[i + 1]) return false;
                if(highindex ==-1)
                {
                    if (A[i] > A[i + 1])
                    {
                        highindex = i;
                    }
                }
                else
                {
                    if (A[i] < A[i + 1])
                        return false;
                }
            }
            return highindex>0 ? true:false;