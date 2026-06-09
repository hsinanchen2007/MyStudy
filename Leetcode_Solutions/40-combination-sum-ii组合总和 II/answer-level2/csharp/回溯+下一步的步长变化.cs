
public class Solution {

    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);
            List<IList<int>> res = new List<IList<int>>();
            List<int> temp_list = new List<int>();
            CombinationSum2_back(res, temp_list, 0, candidates, target);
            return res;
        }
        static public void CombinationSum2_back(List<IList<int>> res, List<int> temp_list, int index, int[] candidates, int target)
        {
            if (0 == target)
            {
                if(!res.Contains(temp_list))
                    res.Add(new List<int>(temp_list));
                return;
            }
            else
            {
                for (int i = index; i < candidates.Length;i++)
                {
                    if (candidates[i] > target)
                        break;
                    temp_list.Add(candidates[i]);
                    CombinationSum2_back(res, temp_list, i+1, candidates, target - candidates[i]);
                    temp_list.RemoveAt(temp_list.Count - 1);
                    while( i<candidates.Length-1 && candidates[i]==candidates[i+1])
                        i++;
                }
            }
        }
}