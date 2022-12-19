public class Solution {
    public int[] TwoSum(int[] nums, int target) {
      var numDic = new Dictionary<int, int>();
      int i = 0;
      foreach (var item in nums)
        {
           numDic.Add(i++, item);
        }

      for (int j = 0; j < numDic.Count; j++)
        {
          if (numDic.ContainsValue(target - numDic[j]))
            {
              //var key = numDic.Where(d => d.Value == target - numDic[j]).Select (d => d.Key); this can return multiple results which meet condition
              var key = numDic.FirstOrDefault(q => q.Value == target - numDic[j]).Key;
              return new int[] { j, key };
            }
        }
        return new int[] { };
    }
}