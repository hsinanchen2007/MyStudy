    def jump(nums): #递归，相当于穷举，但是解一定是对的。
        res_all=[]
        
        def f(loc,num):
            if loc>=len(nums)-1:
                res_all.append(num)
                return
            
            for i in range(0,nums[loc]+1):
                if i==0: 
                    if loc==len(nums)-1:
                        res_all.append(num)
                        return #
                else:
                    f(loc+i,num+1)
                
        f(0,0)
        return min(res_all,default=0)

    def jump(nums): #贪婪算法
        def f(loc,num):
            if loc>=len(nums)-1:
                return num
            
            if loc+nums[loc]>=len(nums)-1:
                return num+1
            else:
                xiayibu=nums[loc+1:loc+nums[loc]+1]
            
            xiayibu_i_daodaMax=0
            i_choice=0
            for i,xiayibu_i in enumerate(xiayibu):
                xiayibu_i_daoda=i+xiayibu_i
                if xiayibu_i_daoda>=xiayibu_i_daodaMax:
                    xiayibu_i_daodaMax=xiayibu_i_daoda
                    i_choice=i
            
            return f(loc+i_choice+1,num+1)
        
        return f(0,0)

    def jump(nums): #顺藤摸瓜
        def f(loc,num):
            if loc==0:
                return num
            
            for i,nums_i in enumerate(nums[:loc]):
                if i+nums_i>=loc:
                    i_choice=i
                    break
            return f(i_choice,num+1)
        res=f(len(nums)-1,0)
        return res