    public class Solution
    {
        public bool RotateString(string A, string B)
        {
            if(A==""&&B=="")
            {
                return true;
            }
            for (int i = 0; i < A.Length; i++)
            {
                A = A.Substring(1, A.Length - 1) + A[0];
                if(A==B)
                {
                    return true;
                }
            }
            return false;
        }
    }