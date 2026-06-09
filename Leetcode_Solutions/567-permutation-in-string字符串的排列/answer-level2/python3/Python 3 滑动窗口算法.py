


        tmp = len(s1)
        taille = len(s2)
        stats = dict()
        for x in s1:
            stats[x]=stats.get(x,0)+1
        left = 0
        right = left + tmp
        stats1 = dict()
        flag = False
        while(right<=taille):
            s = s2[left]
            if(s not in stats):
                stats1.clear()
                left+=1
                right = left + tmp
            else:
                stats1[s]=stats1.get(s,0)+1
                left+=1
                if(left>=right):
                    if(stats1==stats):
                        return True
                    else:
                        delete = s2[right - tmp]
                        stats1[delete]-=1
                        if(stats1[delete]^0==0):
                            stats1.pop(delete)
                        right+=1
            #print(stats1,left,right)
        return flag