第一次玩这个，终于提交成功了。第一次我不小心改了方法名，第二次又没注意数组中可以有重复元素。 
我是这么想的： 先把数组中的元素对象化，设定属性为：下标index，与目标差值result。再将其存成字典：key为元素本身，value为对象本身。然后遍历字典，判断每个元素的value的result是否作为key存在于字典中，如果存在，就是要的结果了。 
遇到的问题：如果数组中存在重复元素，直接存字典就会有问题。所以，我把key存成了double，如果遇到第一个重复的元素，将其+0.1，再遇到就不理会。 
最终，时间复杂度还行，但是占用内存比较多。
```
public class Solution {
    Dictionary<double, Num> d = new Dictionary<double, Num>();
    public int[] TwoSum(int[] nums, int target) {
    int[] result = new int[2];
        for (int i = 0; i < nums.Count(); i++)
        {
            Num num1 = new Num();
            Num n = new Num();
            n.result = target - nums[i];
            n.index = i;
            if (!d.TryGetValue((double)nums[i], out num1))
            {
                d.Add((double)nums[i], n);
            }
            else if (!d.TryGetValue((double)nums[i] + 0.1, out num1))
            {
                d.Add((double)nums[i] + 0.1, n);
            }
            else
            {}
            if(i != 0)
            {
                if (d.ContainsKey((double)n.result))
                {
                    result[0] = n.index;
                    Num num = new Num();
                    d.TryGetValue((double)n.result, out num);
                    result[1] = num.index;
                    if (result[0] != result[1])
                    {
                        return result;
                    }
                }
                else if (d.ContainsKey((double)n.result + 0.1))
                {
                    result[0] = n.index;
                    Num num = new Num();
                    d.TryGetValue((double)n.result + 0.1, out num);
                    result[1] = num.index;
                    if (result[0] != result[1])
                    {
                        return result;
                    }
                }
            }
        }
        return null;
    }
     public class Num
    {
        public int index;
        public int result;
    }
}
```
