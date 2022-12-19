本题很简单，最好的做法显然是用除法、取余做是最好写，最灵活的
但是看了下其他题解，基本上大家都是用同一个写法，觉得很无聊
这里提供一个个人觉得更简洁的写法，C#的
```
public class Solution
{
    public int[][] MatrixReshape(int[][] nums, int r, int c)
    {
        int o_row = nums.Length;
        int o_col = nums[0].Length;
        if (r * c != o_row * o_col) return nums;
        var ret = new int[r][];
        for (int i = 0; i < r; i++)
            ret[i] = new int[c];
        for (int i = 0; i < r * c; i++)
        {
            ret[i / c][i % c] = nums[i / o_col][i % o_col];
        }
        return ret;
    }
}
```
