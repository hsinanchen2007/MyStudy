看到没有C#的来发下题解，思路简单就是在原有结果上一个个添加新数字。
注意List<int>实现了IList<int>接口，List<List<int>>并没有实现IList<IList<int>>，对应的要用List<IList<int>>

```
public class Solution {
    public IList<IList<int>> Subsets(int[] nums) {
            List<IList<int>> res = new List<IList<int>>
            {
                new List<int> { }
            };

            foreach (var num in nums)
            {
                List<IList<int>> currentRes = new List<IList<int>>(res);
                foreach (var l in currentRes)
                {
                    List<int> newList = new List<int>(l);
                    newList.Add(num);
                    res.Add(newList);
                }
            }
            return res;
    }
}
```
