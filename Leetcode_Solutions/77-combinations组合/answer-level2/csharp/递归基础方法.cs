public class Solution {
    public IList<IList<int>> Combine(int n, int k) {
         List<IList<int>> forreturn = new List<IList<int>>();
             Dictionary<int, int> dictest = new Dictionary<int, int>();
            int[] nums1 = new int[n];
            for (int i = 0; i < nums1.Length; i++) nums1[i] = i + 1;
            GetIntArrFromNumArr(nums1, k, ref forreturn, ref dictest);
            return forreturn;
    }
    
    private  void GetIntArrFromNumArr(int[] nums1, int count, ref List<IList<int>> lstintarr, ref Dictionary<int, int> dictest)
        {
            if (count == 0) return;
            for (int i = 0; i <= nums1.Length - count; i++)
            {
                if (dictest.ContainsKey(count) == false)
                    dictest.Add(count, nums1[i]);
                else
                    dictest[count] = nums1[i];
                if (count == 1)
                {
                    lstintarr.Add(dictest.Values.ToList());
                }
                if (count > 1)
                {
                    int[] newnums1 = new int[nums1.Length - i - 1];
                    for (int k = 0; k < newnums1.Length; k++)
                    {
                        newnums1[k] = nums1[i + k + 1];
                    }
                    GetIntArrFromNumArr(newnums1, count - 1, ref lstintarr, ref dictest);
                }
            }
        }
}