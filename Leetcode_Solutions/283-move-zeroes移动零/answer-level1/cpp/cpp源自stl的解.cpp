如果有幸看过cppref上的关于vector中的remove函数，这里的思路非常像。

remove就是将待删除的元素全部放到vector的后端，而其做法就是将左右非待删除的元素逐一排到前面去。

这里是官网给出的可能的实现
```cpp
template< class ForwardIt, class T >
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value)
{
    first = std::find(first, last, value);
    if (first != last)
        for(ForwardIt i = first; ++i != last; )
            if (!(*i == value))
                *first++ = std::move(*i);
    return first;
}
```
和这里这道题覆盖的思路特别像。