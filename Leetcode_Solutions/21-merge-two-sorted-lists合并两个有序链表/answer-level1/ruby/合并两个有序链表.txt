我傻了吧唧的看了人家的题解才明白
```
def merge_two_lists(l1, l2)
    fir = nil
    las = nil
    if l1 == nil
        return l2
    elsif l2 == nil
        return l1
    end

    loop do
        if l1.val > l2.val
            newlist = l2
            l2 = l2.next
        else
            newlist = l1
            l1 = l1.next
        end
        if las == nil
            fir = newlist
            las = newlist
        else
            las.next = newlist
            #p las
            las = newlist
            #p las
        end
        if l1 == nil
            las.next = l2
            break
        elsif  l2 == nil
            las.next = l1
            break
        end
    end
    return fir
end
```
有序链表的结构就是这样的嵌套结构`#<ListNode:0x0000000004fa3c38 @val=1, @next=#<ListNode:0x0000000004fa3b48 @val=1, @next=#<ListNode:0x0000000004fa3b20 @val=3, @next=#<ListNode:0x0000000004fa3af8 @val=4, @next=nil>>>>`

当`las.next = newlist`时，las其实指向上一位newlist，也就是说las等于上一位newlist（原因在于`las = newlist`），将las中的next指向下一位newlist，就完成了改变链表指向的功能。

当`las = newlist`时，las又指向了新的newlist，此时las便等于newlist，也就与上一位newlist再无干系。

因此，此算法的本质就是更改链表中next地址的指向。

最速解直接存了数组 sort就完事了 妙啊
```
def merge_two_lists(l1, l2)
    arr = []
    loop do 
        if l1
            arr << l1.val
            l1 = l1.next
        end
        if l2
            arr << l2.val
            l2 = l2.next
        end
        break if l1.nil? && l2.nil?
    end
   arr.sort
end
```
