```
def transformArray(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        n=len(arr)
        while 1:
            tmp=arr[:]
            for i in range(1,n-1):
                if arr[i-1]>arr[i] and arr[i+1]>arr[i]:
                    tmp[i]+=1
                elif arr[i-1]<arr[i] and arr[i+1]<arr[i]:
                    tmp[i]-=1
            if tmp==arr:
                break
            arr=tmp[:]
        return arr
```
