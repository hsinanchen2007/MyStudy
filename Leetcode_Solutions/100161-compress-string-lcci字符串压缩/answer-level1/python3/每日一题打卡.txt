### 解题思路

一开始是想用count或者counter之类的一下子解决的233333
但问题就在后面的A之类的问题上最后还是选择了一位一位的比较QAQ
其中``range(1,len())``提供了很大的帮助，解决了index out of range 的问题233333
剩下的就是细节问题例如``''``之类的东西www  
**在题解那边看见了groupby的写法所以尝试了一下~**


### 代码
```python3
import itertools
class Solution:
    def compressString(self, S: str) -> str:
	    new_str = ''
	    for key,group in itertools.groupby(S):
		    new_str =new_str + key + str(len(list(group))) 
	    return new_str if len(new_str) < len(S) else S
```

```python3
class Solution:
    def compressString(self, S: str) -> str:
        list1 = list(S)
        a = 1
        c = 0
        if S == '':
            return S
        new_str = S[0]
        for i in range(1,len(S)):
    	    if list1[i] == list1[i-1]:
    		    a +=1
    		    continue
    	    else:
    		    new_str += str(a)
    		    a = 1
    		    new_str += str(list1[i])
        c = a
        new_str += str(c)
        return S if (len(new_str) >= len(S)) else new_str

```