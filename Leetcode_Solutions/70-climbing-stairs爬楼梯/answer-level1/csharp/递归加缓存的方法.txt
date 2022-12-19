这题第一想法就是使用递归的方法，但是直接递归会造成超时，无法通过提交，通过使用Dictionary添加缓存，将之前递归计算得到的结果先缓存下来，后续计算就会提高很高的速度，代码如下：
public class Solution
{
    public static Dictionary<int, int> _dic = new Dictionary<int, int>();

    public int ClimbStairs(int n)
    {
        if (_dic.ContainsKey(n))
        {
            return _dic[n];
        }
        else
        {
            if (n == 1)
            {
                _dic.Add(1, 1);
                return 1;
            }
            else if (n == 2)
            {
                _dic.Add(2, 2);
                return 2;
            }
            else
            {
                int temp = ClimbStairs(n - 1) + ClimbStairs(n - 2);
                _dic.Add(n, temp);
                return temp;
            }
        }
    }
}

这样其实是用空间换时间的做法，思路还是很清楚的，不用递归的方法不太好想，大家可以交流