        public static int[] SumZero(int n)
        {
            int[] sumZ = new int[n];
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                Random rd = new Random();
                int temp = rd.Next((-10),10);
                if (sumZ.Contains(temp))
                {
                    i--;
                    continue;
                }
                sum += temp;
                sumZ[i] = temp;
                if (i == n - 1)
                {
                    if (sum != 0)
                    {
                        sum = 0;
                        i = 0;
                        Array.Clear(sumZ, 0, sumZ.Length);
                    }                    
                }
            }
            return sumZ;
        }