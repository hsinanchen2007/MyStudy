### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]: 
        # 保存结果 
        result = []   
        
        self.dp(result, '(', n-1, n)
        print(result)
        return result 
    
    # 回溯函数 参数：结果集，当前括号字符串，左括号剩余数量，右括号剩余数量
    def dp(self, result, s, l_num, r_num):
        # 如果左括号数量 == 0 有括号数量 == 0 说明得到合法结果，放入结果集
        if l_num == 0 and r_num == 0:
            result.append(s)
            
            return
        if l_num >= 0 and r_num >= l_num:
            self.dp(result, s+'(', l_num-1, r_num)
            self.dp(result, s+')', l_num, r_num-1)
        # print(result, s, l_num, r_num)

```