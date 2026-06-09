```
def nextLargerNodes(head):
    # you题意可知
    # 就是找出离当前值最近的切大于大的数，如果没有就填为0
    # 因此很容易想到用栈去存储最近的历史值
    # 然后通过是否大于当前值，去找到最近的一个数即可
    def slove1():
        # 第一想法，就是倒着遍历 链表，
        # 这样就直接能够保证当前的值，是最近且比他大的值
        if not head: return

        def resverListToStack(root):
            node = ListNode(-1)

            while root:
                p = root.next
                root.next = node.next
                node.next = root
                root = p

            head = node.next

            ans = []
            stack, maxv = [], head.val

            while head:
                curv = head.val
                #保证最后一个值是最近最大的一个值
                while stack and stack[-1] <= curv:
                    stack.pop()

                if not stack or curv == stack[-1]:
                    ans.append(0)
                elif not stack or curv < stack[-1] :
                    ans.append(stack[-1])
                stack.append(curv)
                head = head.next
            return ans

        root = resverListToStack(head)
        return root[::-1]

    def slove2(head):
        # 其实不用这么麻烦，思维定式，让我总喜欢倒着去遍历
        # 其实在stack存储历史值的过程中，已经可以去得到结果了
        # 就是找到最近的比他大的值的时候，就可以得出结果了，不必要只是为了保留当前最近的最大状态
        # 所以 直接正序遍历，然后用栈存储不满足的位置已经值，
        # 然后依次遍历，判断是否有满足大于历史值的，如果满足就填上当前值
        # 而当前值就保证了，是最近的值。
        # 和方法1逻辑刚好相反
        ans = [ ]
        stack, idx = [ ], 0
        while head:
            curv = head.val
            while stack and stack[ -1 ][1] < curv:
                ans[stack.pop()[0]] = curv
            ans.append(0)
            stack.append((idx, curv))
            idx += 1
            head = head.next
        return ans

    slove1()
    slove2(head)
```
