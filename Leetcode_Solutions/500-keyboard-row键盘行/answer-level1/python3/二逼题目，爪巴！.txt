### 解题思路
![QQ截图20200108180319.png](https://pic.leetcode-cn.com/423a0675e8390f8cb25addf45b6e58b1099bc33eb0e1a7683204e2a9bec8bb07-QQ%E6%88%AA%E5%9B%BE20200108180319.png)

没什么好说的呀，Python处理字符串

### 代码

```python3
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row1="qwertyuiop"
        row2="asdfghjkl"
        row3="zxcvbnm"
        res=[]
        for each_word in words:
            each_word1=each_word.lower()
            i=0
            flag=True
            for each_letter in each_word1:
                if row1.find(each_letter)!=-1:
                    if i==0:
                        i=1
                    else:
                        if i!=1:
                            flag=False
                            break
                        else:
                            pass
                elif row2.find(each_letter)!=-1:
                    if i==0:
                        i=2
                    else:
                        if i!=2:
                            flag=False
                        else:
                            pass
                else:
                    if i==0:
                        i=3
                    else:
                        if i!=3:
                            flag=False
                        else:
                            pass
            if flag==True:
                res.append(each_word)
        return res
```