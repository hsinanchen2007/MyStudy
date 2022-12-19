class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        arr=arr1+arr2+arr3
        print(arr)
        a=sorted(arr)
        b=[]
        print(sorted(arr))
        for i in range(len(arr)-2):
            if a[i]==a[i+1]==a[i+2]:
                print(a[i],a[i+1],a[i+2])
                b.append(a[i])
            else:
                i=i+1
            i=i+1
        return b

