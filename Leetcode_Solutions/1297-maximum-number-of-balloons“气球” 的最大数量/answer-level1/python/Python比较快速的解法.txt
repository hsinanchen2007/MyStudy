
```
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        ##text长度为1到10000
        ##balloon   1个b 1个a 2个l 2个o 1个n
        dictAlpha = {"a":0,"b":0,"c":0,"d":0,"e":0,"f":0,"g":0,"h":0,"i":0,"j":0,"k":0,"l":0,"m":0,"n":0,"o":0,"p":0,"q":0,
                        "r":0,"s":0,"t":0,"u":0,"v":0,"w":0,"x":0,"y":0,"z":0}
        for t in text:
            dictAlpha[t] += 1
        #各个字母的个数          
        return min(dictAlpha["b"],dictAlpha["a"],dictAlpha["l"]/2,dictAlpha["o"]/2,dictAlpha["n"])
```

