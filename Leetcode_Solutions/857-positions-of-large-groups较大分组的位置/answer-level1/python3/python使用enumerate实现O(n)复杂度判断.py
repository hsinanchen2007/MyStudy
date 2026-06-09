```python
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        if len(S)<3:
            return []
        
        # 用于判断是否进入重复
        flag = 0
        pre = S[0]
        res = []
        
        for k, v in enumerate(S): 
            if v==pre:
                
                if flag==0:
                    # 避免最后两个字母相同的情况
                    if k==len(S)-1:
                        break
                    else:
                        k = k-1 if k!=0 else 0
                        res.append([k, 0])
                # 若已进入循环将结束索引设置为当前索引
                else:
                    res[-1][1] = k
                    
                flag = 1                
            
            else:
                flag = 0
                if len(res) and res[-1][1]-res[-1][0] < 2:
                    res.pop()
                pre = v

        return res