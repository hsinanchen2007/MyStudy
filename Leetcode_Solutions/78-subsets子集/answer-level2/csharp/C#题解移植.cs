# 自己设计的做法
```csharp
public IList<IList<int>> Subsets(int[] nums)
{
    IList<IList<int>> list = new List<IList<int>>();
    list.Add(new List<int>());
    int len;
    for (int i = 0; i < nums.Length; i++)
    {
        len = list.Count;//记录要复制的元素数
        for (int j = 0; j < len; j++)//复制子集
        {
            list.Add(new List<int>(list[j]));
        }
        for (int k = len; k < list.Count; k++)//对后面复制的子集加入当前元素
        {
            list[k].Add(nums[i]);
        }
    }
    return list;
}
```
![image.png](https://pic.leetcode-cn.com/a5814ff7b07a3acaca422d88f918f764749f44cc7101874407dd68330fd0a059-image.png)

# 回溯法
```csharp
//回溯法
private IList<IList<int>> res;
private void find(int[] nums, int begin, IList<int> pre)
{
    // 没有显式的递归终止
    res.Add(new List<int>(pre));// 注意：这里要 new 一下
    for (int i = begin; i < nums.Length; i++)
    {
        pre.Add(nums[i]);
        find(nums, i + 1, pre);
        pre.RemoveAt(pre.Count - 1);// 组合问题，状态在递归完成后要重置
    }
}
public IList<IList<int>> Subsets(int[] nums)
{
    int len = nums.Length;
    res = new List<IList<int>>();
    if (len == 0)
    {
        return res;
    }
    IList<int> pre = new List<int>();
    find(nums, 0, pre);
    return res;
}
```
![image.png](https://pic.leetcode-cn.com/6b50bc4e5b905122a7060f36db7ef05b4ad1f5ff06cf20023e50eed495ddf24f-image.png)

**以上是对题解的c#移植，详细解答请看精选题解。**
