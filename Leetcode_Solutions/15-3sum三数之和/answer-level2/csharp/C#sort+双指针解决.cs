### 解题思路
我们先对给定的数组用sort进行排序，得到一个从小到大排列的数组，然后，我们从第一个数字开始，指定它为i，当我们的nums[i]要大于nums[i-1]时，j从i+1开始，k从数组的末尾开始，我们计算nums[j]+nums[k]和-nums[i]的大小，如果前者大，那么我们让k--，这样得到的值小一点，如果后者大，我们让j++这样得到的值大一点，如果相等了，那么说明我们找到了一组数字，把他存入list中，然后我们跳过和num[j]和nums[k]相等的数字，然后再去找直到j=k。
凡是做过第一题的人遇到这个题都会有点思路，但是重点在于如何去掉重复的，我们采用的方法是，先固定一个，然后去找这一个后面的数字里有没有两个数字和它相加等于0，如果找到了，那么不仅要注意把结果存起来，还要从此时的j开始往后找所有和nums[j]相等的数字，跳过他们，然后从此时的k开始往前找，跳过所有和nums[k]相等的数字，除此之外，对每一个i我们都要保证它不等于它前面的数字（如果他等于他前面的数字，那么这一轮找到的数字组合和上一轮相同），这样去掉重复的组合。

### 代码

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
         IList<IList<int>> r = new  List<IList<int>>();
         Array.Sort(nums);
         for (int i = 0; i < nums.Length; i++)
         {
             if (i != 0 && nums[i] == nums[i - 1])
                continue;
             int j = i + 1, k = nums.Length - 1;
             while (j < k)
             {
                 if (j == i)
                 {
                     j++;
                     continue;
                 }
                 if (k == i)
                 {
                     k--;
                     continue;
                 }
                 if (nums[j] + nums[k] < 0 - nums[i])
                 {
                     j++;
                 }
                 else if(nums[j] + nums[k] > 0 - nums[i])
                 {
                     k--;
                 }
                 else
                 {
                     IList<int> a = new List<int>();
                     int[] ans = new int[3];
                     if (i > k)
                        ans = new int[3] {nums[j], nums[k], nums[i]};
                     else if (i < j)
                        ans = new int[3]{nums[i], nums[j], nums[k]};
                     else
                        ans = new int[3]{nums[j], nums[i], nums[k]};
                     a = ans;
                     r.Add(a);
                     j++;
                     k--;
                     while (j < k && nums[j] == nums[j-1])
                        j++;
                     while (j < k && nums[k] == nums[k + 1])
                        k--;
                 }
             }
         }
         return r;
    }
}
```