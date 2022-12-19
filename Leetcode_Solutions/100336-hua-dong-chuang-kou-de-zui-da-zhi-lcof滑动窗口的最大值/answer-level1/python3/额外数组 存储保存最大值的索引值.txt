- 保证a[0]始终保存当前窗口最大值的索引
```
def maxSlideNum(arr,k):
    a = []#存索引 a[0]最大 a[-1]最小
    res = []
    for i in range(len(arr)):
        if not a: 
            a.append(i)
        else:
            if arr[i] > arr[a[0]]:
                a = [i]
            else:
                if i > a[0]+k-1:
                    a.pop(0)
                while a and arr[i] > arr[a[-1]]:
                    a.pop()
                a.append(i) 
        
        if i >=k-1:
            res.append(arr[a[0]])
    return res
print(maxSlideNum([1,3,1,2,0,5],3))
```
