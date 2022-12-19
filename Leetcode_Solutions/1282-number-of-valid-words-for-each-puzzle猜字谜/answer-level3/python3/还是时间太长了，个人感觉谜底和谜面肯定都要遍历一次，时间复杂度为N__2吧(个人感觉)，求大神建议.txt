class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        li=[]
        for puzzle in puzzles:
            count=0
            for word in words:
                a=set(list(word))
                b=set(list(puzzle))
                if list(puzzle)[0] in list(word) and a|b==b:
                    count+=1    
            li.append(count)
        return li