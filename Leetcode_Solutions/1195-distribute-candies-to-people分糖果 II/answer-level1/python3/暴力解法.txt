class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        lst=[0]*num_people
        candies_need=1
        num=0
        while not candies<=candies_need:
            
            candies=candies-candies_need
            
            lst[num]+=candies_need
            num=int((num+1)%num_people)
            candies_need+=1
        lst[num]+=candies
        return lst