// #### 我是个菜鸟,我相信肯定有跟我一样的菜鸟,一开始连题目都看不懂的QAQ,所以先解释一下题目
// - 题目说的是逆序,所以我们可以直接从两个链表的第一个数字开始加起 (之前看题解看了一脸蒙蔽,为啥大家都直接从第一个数就开始加起来了,个位不应该是最后一个吗? 奥 原来是逆序,好好审题,先拍自己一巴掌)
// - 搜索题解,基本没啥人用swift写的,可能是因为执行效率不高和语法问题,所以在这里新增swift解法
// - 因为是菜鸟,所以只做了实现,没有什么优化
// - 解题思路是参照的别人的,反正能写出来理解了最后就都是自己了的嘛(我好不要脸!)

// ### 说一下解题思路
// 我们用一个while循环同时去遍历两个链表
// 外层循环保留一个进位值是0
// - 正常情况
//     - :这一次遍历,每个链表中都有值,分别为 p.val 和q.val
//     - 我们用这两个值相加后再加上进位值, 对应下面代码中的x+y+additon
//     - 加完之后让新链表的next等于加出来的值去模10(其实就是取个位数,小学加法)
//     - 然后如果超过10就让外层的那个进位值变成1,不超过就还是0 (这一步是为了让下一次的while循环中能知道进位值是多少)
//     - 做完这些操作之后 我们让 p = p.next q = q.next (这是为了让下一次循环时能去计算下一位) pointer  = pointer.next  (这是为了让我们下一层计算完之后 把计算值给新链表的时候能给点下一个节点)

// - 非正常情况 
//     - 如果我们next到某一步之后,有一个链表里面已经没值了,那我们就用0去跟另一个链里的值相加,其他过程一样

// ### 好了 到这里整个while就结束了
// - 最后一步,我们算完之后,如果最后一步的进位值是1,很显然我们要给新链表最后加一个1
//   举个栗子 🌰 :  9->9 + 1 最后要变成 0->0->1 这个001里的1就是最后加的
// - 然后这个时候由于我们的pointer 已经是是新链子的最后一个节点了 所以我们不能返回pointer
// - 所以你看 一开始咱们让pointer = new ; 所以这个时候我们返回new.next就可以啦

// ###总结一下吧,这是我第一次在leetcode上写题解,其实很多题目看明白了就都不难了,希望静下心来,以后应该可以解出更多滴题呀,大家一起加油

// 下面是代码


// ```
lass Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var p = l1;
        var q = l2;
        
        var new:ListNode = ListNode.init(0);
        
        var pointer:ListNode = new;
        
        
        var addition  = 0;
        while p != nil || q != nil {
            let x = (p != nil) ? p!.val : 0;
            let y = (q != nil) ? q!.val : 0;
            
            let  new = addition + x + y;
            
            let v = new%10;
            
            pointer.next = ListNode.init(v);
            
            pointer = pointer.next ?? ListNode.init(0);
            
            addition = new/10;
            
            if p != nil {
                p = p?.next;
            }
            if q != nil {
                q = q?.next;
            }
           
            
        }
        if addition != 0 {
            pointer.next = ListNode.init(1);
        }
        return new.next;
    }
}
// ```
