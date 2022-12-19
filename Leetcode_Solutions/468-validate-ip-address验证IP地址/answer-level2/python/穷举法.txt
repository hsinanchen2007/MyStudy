
```
class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        sixteenList = ["0","1","2","3","4","5","6","7","8","9","A","a","B","b","C","c","D","d","E","e","F","f"]
        
        if "." in IP:#可能是ipv4
            #不是四位
         #   print IP.count(".")##输出3
            if IP.count(".") != 3:#有且只有3个点
                return "Neither"
            if len(IP.split("."))!=4:
                return "Neither"
            #进一步判断
            for every in IP.split("."):
                try:
                    int(every)
                    if (every[0] == "0" and len(every)>1) or int(every)>255 or int(every)<0 or "-" in every:#子段有0开头  int(every)可以是-0
                        return "Neither"
                except:
                    return "Neither"
            return "IPv4"
                
        elif ":" in IP:#可能是ipv6
            #进一步判断
            if IP.count(":") != 7:#有且只有7个:
                return "Neither"
            if len(IP.split(":"))!=8:#防止空位
                return "Neither"
            for every in IP.split(":"):
                print every#2001输出
                print len(every)#4
                if len(every)>4: #每个子段的长度
                    return "Neither"
                if "" == every:######不能是in
                    print "yes"#???
                    return "Neither"
                for e in every:
                    print e
                    if e not in sixteenList:
                        print "YYY"
                        return "Neither"#不是16进制   
            return "IPv6"
        else:
            return "Neither"
            
        
        
        
        
```
