与LeetCode官方算法思路一样的，却因输出与表达位置不一样失败，求问为啥
class LogSystem(object):

    def __init__(self):
        self.dictionary = {}

        

    def put(self, id, timestamp):
        """
        :type id: int
        :type timestamp: str
        :rtype: None
        """
        self.dictionary[id] = timestamp

        

    def retrieve(self, s, e, gra):
        """
        :type s: str
        :type e: str
        :type gra: str
        :rtype: List[int]
        """
        def CalcList(targetList, stopNum):
            listValue = 0
            for i in range(0,stopNum):
                if i == 0:
                    listValue = listValue + (int(targetList[i]) - 2000) * 31536000
                if i == 1:
                    listValue = listValue + (int(targetList[i]) - 1) * 2678400
                if i == 2:
                    listValue = listValue + (int(targetList[i]) - 1) * 86400
                if i == 3:
                    listValue = listValue + int(targetList[i]) * 3600
                if i == 4:
                    listValue = listValue + int(targetList[i]) * 60
                if i == 5:
                    listValue = listValue + int(targetList[i])    
            return listValue 
        result = [] 
        sList = s.split(":")
        eList = e.split(":")
        for it in self.dictionary :
            if gra == "Year":
                endNum = 1
            elif gra == "Month":
                endNum = 2
            elif gra == "Day":
                endNum = 3
            elif gra == "Hour":
                endNum = 4         
            elif gra == "Minute":
                endNum = 5
            elif gra == "Second":
                endNum = 6
            dictList = self.dictionary[it].split(":")   
            if endNum == 0:
                if dictList[0] >= sList[0] and dictList[0] <= eList[0]:
                    result.insert(0, it)
            else:
                sValue = 0
                eValue = 0
                dictValue = CalcList(dictList,endNum)
                sValue = CalcList(sList,endNum)
                eValue = CalcList(eList,endNum)
                if dictValue>=sValue and dictValue<=eValue:
                    result.insert(0, it)
        return result
# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(s,e,gra)