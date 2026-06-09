题解很多，不重复了。这个实现用的是栈。但是我想说说接口。

迭代器只有两个接口 bool HasNext和 T Next。那设计就可以偏向两种方向。
遍历先缓存其实不是迭代器的实现方法。如果能遍历出结果了，为什么需要迭代器呢？不符合因果逻辑。为做题而做就没意思了。
那设计的时候还要考虑计算的消耗。计算的话比如查询操作更多，那就把计算放在Next。反之把计算放在HasNext中。
可能不是所有迭代器都是线性的，所以实现的时候侧重是可以选的。
一般情况下，如果没有要求，我倾向于把计算放在Next里。为什么呢？Next要返回值，那么计算是有代价的，一般来说用的人会预期到这一点。


```c#
public class NestedIterator {
    private Stack<NestedInteger> _stack;
    private int? _next;

    public NestedIterator(IList<NestedInteger> nestedList) {
        _stack = new Stack<NestedInteger>();
        foreach (var l in Enumerable.Reverse(nestedList))
        {
            _stack.Push(l);
        }
        
        // 既然决定了实现接口的方向，那么在这里构造的时候支付一次代价
        _next = -1; // fake to start
        Next();
    }
    
    public bool HasNext() {
        return _next != null;
    }

    public int Next() {
        // 如果HasNext没有被正确使用，这样就可以保护使用者见到Exception而不是有非预期行为
        // 按照接口，如果没有用HasNext使用Next是非预期的行为。报错了还能修，这样不影响上层依赖这个基础类的逻辑的debug
        if (_next == null) {
            throw new Exception("Iterator is exhausted.");
        }
        var ans = (int)_next;
        
        _next = null;
        while (_stack.Count() > 0 && _next == null) {
            var cur = _stack.Pop();
            if (cur.IsInteger()) {
                _next = cur.GetInteger();
            } else {
                foreach (var l in Enumerable.Reverse(cur.GetList()))
                {
                    _stack.Push(l);
                }
            }
        }
        return ans;
    }
}

```

