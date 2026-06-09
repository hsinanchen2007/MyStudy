public class Solution {
    public string FindLongestWord(string s, IList<string> d) {
        List<string> lst = new List<string>();
            int maxlength = 0;
            for(int i=0;i<d.Count;i++)
            {
                bool candelete = true;
                if (maxlength <= d[i].Length)
                {
                    int findindex = -1;
                    for (int j = 0; j < d[i].Length; j++)
                    {
                        findindex = s.IndexOf(d[i][j], findindex+1);
                        if(findindex<0)
                        {
                            candelete = false;
                            break;
                        }
                    }
                    if (candelete)
                    {
                        if (maxlength < d[i].Length)
                        {
                            lst.Clear();
                            lst.Add(d[i]);
                            maxlength = d[i].Length;
                        }
                        else if (maxlength == d[i].Length)
                        {
                            lst.Add(d[i]);
                        }
                    }
                }
            }
        
            if (lst.Count == 1)
                return lst[0];
            else if (lst.Count == 0) return "";
            else
            {
                string min = lst[0];
                for (int i = 1; i < lst.Count; i++)
                {
                    for (int j = 0; j < min.Length; j++)
                    {
                        if (min[j] - lst[i][j] > 0)
                        {
                            min = lst[i];
                            break;
                        }
                        else if (min[j] - lst[i][j] < 0)
                        {
                            break;
                        }
                    }
                }
                return min;
            }
        }
    
   
}