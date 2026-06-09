```
public class _364_加权嵌套序列和_2
{
    public int DepthSumInverse(IList<NestedInteger> nestedList)
    {
        var depth = depthSum(nestedList);
        return walk(nestedList, depth);
    }

    public int depthSum(IList<NestedInteger> nestedList)
    {
        var depth = 0;
        foreach (var nl in nestedList)
        {
            if (!nl.IsInteger())
            {
                var d = depthSum(nl.GetList());
                if (d > depth)
                {
                    depth = d;
                }
            }
        }

        depth++;

        return depth;
    }

    public int walk(IList<NestedInteger> nestedList, int depth)
    {
        if (depth == 0)
        {
            return 0;
        }
        var sum = 0;
        var sum_sub = 0;
        foreach (var nl in nestedList)
        {
            if (nl.IsInteger())
            {
                sum += nl.GetInteger();
            }
            else
            {
                sum_sub += walk(nl.GetList(), depth - 1);
            }
        }

        return sum * depth + sum_sub;
    }
}
```
