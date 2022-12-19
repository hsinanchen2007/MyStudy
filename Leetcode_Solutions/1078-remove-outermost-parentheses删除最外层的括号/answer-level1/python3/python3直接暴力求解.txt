简单的思路，用栈求所有的“原语”，然后取每个“原语”，去掉最外面的左右括号，加到一起，直接求解。
利用一个j标记“原语”的头
很容易考虑，但是速度慢，空间占用高。
```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
    	#栈为空，取出的就是一个primitive
    	stack=[]
    	primitive=[]
    	res=''
    	j=0
    	if S == None:
    		return ''
    	for i in range(len(S)):
    		if S[i]=='(':
    			stack.append(S[i])
    		else:
    			stack.pop()
    		if stack==[]:
    			# 栈空，说明这个是一个primitive
    			primitive.append(S[j:i+1])
    			j=i+1

    	for i in range(len(primitive)):
    		res+=primitive[i][1:-1]
    	return res
```
