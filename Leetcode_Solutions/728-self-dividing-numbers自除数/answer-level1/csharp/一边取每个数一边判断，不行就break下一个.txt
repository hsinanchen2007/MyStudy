public class Solution {
    public IList<int> SelfDividingNumbers(int left, int right) {
         List<int> forreturn = new List<int>();
            for(int i=left;i<=right;i++)
            {
                if(i.ToString().Contains("0")==false)
                {
                    int rawi = i;
                    bool res = true;
                    while(i>0)
                    {
                        if (rawi % (i % 10) != 0)
                        { res = false; break; }
                        i = i / 10;
                    }
                    if (res) forreturn.Add(rawi);
                    i = rawi;
                }
            }
            return forreturn;
    }
}