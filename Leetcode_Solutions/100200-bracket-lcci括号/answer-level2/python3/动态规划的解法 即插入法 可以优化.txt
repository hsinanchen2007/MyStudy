  
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        if n==1:
            res.append('()')
        else:
            temp='()'
            tempres=[]
            tempres.append(temp)
            lens=n*2
            while(n>1): #只需要插入n-1次
                trans=[]
                for i in tempres:
                    new=self.insert(i)
                    for j in new:
                        if j not in trans:
                            trans.append(j)
                tempres=trans
                n-=1
            for item in tempres:
                if len(item)==lens:
                    res.append(item) 
        return res

            

    def insert(self,temp):# 将()插入到temp中
        pair=self.get_left_and_right(temp)
        res=[]
        for i in pair:
            l=i[0]
            r=i[1]
            #两种插入方式
            newstr=temp[0:l]+'('+temp[l:r]+')'+temp[r:len(temp)]
            res.append(newstr)
            if l-1>=0 and r+1<=len(temp):
                newstr2=temp[0:l-1]+'('+temp[l-1:r+1]+')'+temp[r+1:len(temp)]
                res.append(newstr2)

        res.append(temp+'()')
        res.append(''+temp)
        return list(set(res))
    

    def get_left_and_right(self,temp):
        #找出所有括号的位置
        pair=[]
        all_pair=len(temp)/2
        i=0 #从第0位开始数左括号
        while(all_pair>0):
            if temp[i]=='(':
                count=1
                index=i+1
                while(count>0):
            #找相对应的括号 遇到左括号+1 右括号-1 如果count为0 则说明找到啦
                    if index<len(temp):
                        if temp[index]=='(': 
                            count+=1
                        else:
                            count-=1
                        if count==0:
                            pair.append([i,index])
                            all_pair-=1
                    index+=1
            i+=1
        return pair



