int max = -1;
            for(int i=0;i<A.Length;i++)
            {
                if (A[i] > max)
                    max = A[i];
                else
                    return i-1;
            }
            return -1;