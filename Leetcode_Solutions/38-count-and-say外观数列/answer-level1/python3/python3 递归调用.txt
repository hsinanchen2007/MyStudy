思路：用递归方法，不断调用上一个n所返回的字符串str，通过计算上一个数的逻辑来得到本n的逻辑字符串
```
        if   n==1 :return "1"
        elif n==2 :return "11"    
        elif n==3 :return "21"    
        elif n==4 :return "1211"    
        elif n==5 :return "111221"    
        else :
            strs = self.countAndSay(n-1)
            lis = list(strs)
            sts =[]
            start = len(lis)-1
            q = lis[start]
            for i in range(len(lis))[::-1]:        
                temp =[]
                q = lis[start]
                
                if lis[i]!=q:
                    temp = lis[i+1:]
                    del lis[i+1:]   
                    start = i  
                    lens = 0 
                    sts.append(int(q))
                    sts.append(temp.count(q))
            sts.append(int(lis[0]))
            sts.append(lis.count(lis[0]))              
            sts_reverse = list(reversed(sts))
            return "".join(str(i) for i in sts_reverse)
```
