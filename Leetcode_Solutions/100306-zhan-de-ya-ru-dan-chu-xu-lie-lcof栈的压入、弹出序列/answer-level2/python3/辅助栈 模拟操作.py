```

# 使用一个辅助stack模拟push 及 pop操作，
# 每push一个数，检查辅助stack末尾和poped stack开始，如果相同，同时pop
#     结算条件是st[-1] != poped[0] 或者 st 跟 poped有一个为空
    def valid(self,s,t):
        st = []
        for num in s:
            st.append(num)
            if num == t[0]:
                st.pop()
                t.pop(0)
            # print(st,t)        
            while t and st:
                if t[0] == st[-1]:
                    t.pop(0)
                    st.pop()
                else:
                    break
        if len(st)==0:
            return True
        else:
            return False

print(Solution().valid([8,2,1,4,7,9,0,3,5,6],[1,2,7,3,6,4,0,9,5,8]))
print(Solution().valid([1,2,3,4,5],[4,5,3,2,1]))
print(Solution().valid([2,1,0],[1,2,0]))
```
