直接将A，B放到一起排序，放到nums中。 
将未匹配的b放到堆栈stack_b中，遍历nums中的元素：
如果堆栈stack_b为空，
    如果元素属于a， 此时没有比a小的b需要匹配，扔到unused_a中
    如果元素属于b,待匹配后面更大的a，压栈
如果堆栈stack_b不为空
    如果元素属于a， 找到一个匹配对，出栈，放到ans中
    如果元素属于b,继续压栈

最后将未匹配的unused_a和stack_b放到ans中，按照b的索引值排序，得到结果
```
class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        # A代号为'a'，B代号为'b'；则对于A,B中相同的数字， A排在前面，简化判断
        nums = sorted(itertools.chain( [(i, 'a', index) for index, i in enumerate(A)], [(j, 'b', index) for index, j in enumerate(B)]))         
        ans, unused_a, stack_b = [], [], []
        for value, abtype, index in nums:
            if not stack_b:
                if abtype == 'a': # A中元素, 堆栈中没有需要匹配的b
                    unused_a.append(index)
                else: # B中元素，入栈
                    stack_b.append(index)
            else:
                if abtype == 'a': # A中元素，消掉堆栈中的1个B
                    ans.append((stack_b.pop(), index)) # B的索引值在前，A的索引值在后                    
                else: # B中元素，继续入栈
                    stack_b.append(index)        
        ans.extend(zip(unused_a, stack_b))  # 将未匹配的ab任意组队
        return [A[index_a] for index_b, index_a in sorted(ans)]
```
