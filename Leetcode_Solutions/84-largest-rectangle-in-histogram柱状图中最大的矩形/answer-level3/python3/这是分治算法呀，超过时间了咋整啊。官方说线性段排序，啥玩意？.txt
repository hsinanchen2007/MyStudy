    def largestRectangleArea(self, heights: List[int]) -> int:
        l=heights
        s=[]
        def fenzhi(l):
            if l==[]:return

            l_min=min(l,default=0)
            l_s=l_min*len(l)
            s.append(l_s)

            l_fenkai=[]
            l_fenkai_i=[]
            for i in l:
                if i!=l_min:
                    l_fenkai_i+=[i]
                else:
                    if l_fenkai_i!=[]:
                        l_fenkai+=[l_fenkai_i]
                    l_fenkai_i=[]
            if l_fenkai_i!=[]:
                l_fenkai+=[l_fenkai_i]
            for i in l_fenkai:
                fenzhi(i)
        fenzhi(l)
        return max(s,default=0)
