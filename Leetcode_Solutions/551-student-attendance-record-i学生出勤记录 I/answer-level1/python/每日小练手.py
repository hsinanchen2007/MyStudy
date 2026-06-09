### 解题思路
思路主要是通过检测有无多余一个A，然后将出现了L的序号提取出来，在前后加一个，切片进行比较

### 代码

```python
class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        present = list(s)
        le = len(present)
        r= 0 
        i = 0
        cou=[]
        if present.count("A")<=1:
            r=1
        else:
            return False
        while i < le:
            if present[i] == "L":
                cou.append(i)
            i+=1
        cou.insert(0,0)
        cou.append(0)
        i=2
        while i <len(cou)-1:
            if cou[i]-cou[i-1]==1:
                if cou[i+1]-cou[i]==1:
                    return False
            i+=1
        if r == 1:
            return True
                
```