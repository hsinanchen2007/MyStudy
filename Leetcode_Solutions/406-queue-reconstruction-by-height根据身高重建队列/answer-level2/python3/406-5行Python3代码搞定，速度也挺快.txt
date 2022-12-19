class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people=sorted(people,key=lambda x: (x[0],x[1] and -x[1]),reverse=True) #排序，[0]先降序，[1]升序
        res=[]
        for item in people:
            res.insert(item[1],item) #插入，搞定。自己写了个链表，但是耗时很大，没有内置的List插入好用
        return res