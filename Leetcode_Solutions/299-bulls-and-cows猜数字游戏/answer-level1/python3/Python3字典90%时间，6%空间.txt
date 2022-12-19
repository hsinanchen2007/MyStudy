思路：同时遍历两个字符串，若当前索引的两个元素相同，A+1。若不同，两个值设为a、b,分别添加入两个字典，dic1[a]++;dic2[b]++。遍历完成后，再针对secret中每个元素对两字典进行遍历，取小的键值加到B上。举例：如对secret中某一个x字符，dic1[x]=4,dic2[3],说明secret中有四处x字符未与guess对应，而guess中只有3处是x的地方未与secret对应。如secret:xxxxxaaa、guess:aaaaxxxx,前四位xxxx与aaaa全不对应，dic1[x]=4，第五位均为x直接A+1，不对字典进行操作。后3位xxx和aaa不同，dic2[x]=3，这种情况下guess猜对的x字符应该是3而不是4。
python3：
```
class Solution:
    def getHint(self, secret, guess):
        A,B=0,0
        dic1,dic2={},{}
        siz=len(secret)
        for i in range(siz):
            if secret[i]==guess[i]:
                A+=1
            else:
                if secret[i] not in dic1:
                    dic1[secret[i]]=1
                else:
                    dic1[secret[i]]+=1
                if guess[i] not in dic2:
                    dic2[guess[i]]=1
                else:
                    dic2[guess[i]]+=1
        for x in dic1:
            if x in dic2:
                B+=min(dic1[x],dic2[x])
        return str(A)+'A'+str(B)+'B'
```
