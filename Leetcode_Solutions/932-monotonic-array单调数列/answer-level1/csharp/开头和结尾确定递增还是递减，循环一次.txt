public static bool IsMonotonic2(int[] A)
        {
            if (A.Length == 1) return true;
            string dd = "";
            if (A[0] < A[A.Length - 1]) dd = "dz";
            if (A[0] > A[A.Length - 1]) dd = "dj";
            if (A[0] == A[A.Length - 1]) dd = "dd";
            for (int i = 0; i < A.Length - 1;i++)
            {
                if(A[i]<A[i+1])
                {
                    if (dd == "dj" || dd == "dd")
                        return false;
                }
                else if (A[i] > A[i + 1])
                {
                    if (dd == "dz" || dd=="dd")
                        return false;
                }
            }
            return true;
        }