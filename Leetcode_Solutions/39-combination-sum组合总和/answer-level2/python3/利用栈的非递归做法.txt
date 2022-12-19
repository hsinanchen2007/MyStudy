**思路：**
简单来说就是：自大而小向栈里填入元素。

细节主要是下面这些，注释里也有写到：
1. 当结果大于或等于target时，退栈并寻找应当入栈的下一个元素，也即比出栈元素较小的元素；
2. 如果出栈元素已经是最小元素，则持续退栈；直到栈空，或者出栈元素不是最小元素为止；
3. 如果栈空，从候选集中寻找最大元素填满，并且在候选集中删除该元素。
4. 如果栈空且候选集空，算法结束。

例如[2,3]，target=6。
首先用3填满，栈中为[3,3]，候选集为[2]。
满足条件后输出，3退栈，两个2进栈。栈中为[3,2,2]，结果超出了6。
由于2是最小元素，所以持续退栈，直到栈空。
候选集中只有2，用2填满，栈中为[2,2,2]，候选集为空。
输出结果，栈退空。由于此时候选集也为空，算法结束。

相比于递归，代码繁杂，尚有优化空间。还请多多包涵。

**代码：**
```python []
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        mySum = 0
        st, res = [], []
        
        # 记录每一个元素的下标，以快速寻找退栈后应当进栈的元素
        mp = {}
        for i in range(len(candidates)):
            mp[candidates[i]] = i

        # 用候选集中的最大元素填满栈，并在候选集中删除该元素
        tail = candidates[len(candidates) - 1]
        while mySum < target:
            st.append(tail)
            mySum += tail
        candidates.pop()

        while st:
            # 若满足条件，输出
            if mySum == target:
                res.append(copy.copy(st))
            # 末尾元素退栈，寻找小于其的第一个元素
            tail = st.pop()
            mySum -= tail
            pos = mp[tail] - 1
            # 如果退栈的已经是候选集中最小元素，则持续退栈
            # 直到退栈元素不是候选集中最小，或者栈为空为止
            while st and pos == -1:
                tail = st.pop()
                mySum -= tail
                pos = mp[tail] - 1
            # 栈非空，用下一个元素填满栈
            if st:
                cur = candidates[pos]
                while mySum < target:
                    st.append(cur)
                    mySum += cur
            # 栈空而候选集非空，用候选集中的最大元素填满栈，并在候选集中删除该元素
            elif candidates:
                tail = candidates[len(candidates) - 1]
                while mySum < target:
                    st.append(tail)
                    mySum += tail
                candidates.pop()
        return res
```