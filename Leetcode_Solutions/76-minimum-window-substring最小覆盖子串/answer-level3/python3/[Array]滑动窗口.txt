## 思考
1. 遍历一次数组 -> 双指针`cur_st`, `cur_ed` -> 什么时候移动`cur_st`, 什么时候移动`cur_ed`

## Solutions
```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ''' Sliding window
        '''
        cnt_char = {}
        for ichar in t:
            cnt_char.setdefault(ichar, 0)
            cnt_char[ichar] += 1
        
        cur_st, cur_ed = 0, 0
        cnt_cur = {}
        cnt_cur[s[0]] = 1
        
        def is_valid(ref_cnt, targ_cnt) -> bool:
            # print(ref_cnt, targ_cnt)
            for ikey in ref_cnt:
                if ikey in targ_cnt:
                    if targ_cnt[ikey] < ref_cnt[ikey]:
                        return False
                else:
                    return False
            return True

        res_cnt = len(s)+100
        while True:
            if is_valid(cnt_char, cnt_cur):
                if cur_ed-cur_st+1 < res_cnt:
                    res_cnt = min(res_cnt, cur_ed-cur_st+1)
                    if res_cnt == 1:
                        return s[cur_st]
                    else:
                        res = s[cur_st:cur_ed+1]
                cnt_cur[s[cur_st]] -= 1
                cur_st += 1
            else:
                if cur_ed < len(s)-1:
                    cur_ed += 1
                    cnt_cur.setdefault(s[cur_ed], 0)
                    cnt_cur[s[cur_ed]] += 1
                else:
                    break

        if res_cnt <= len(s):
            return res
        else:
            return ''
```