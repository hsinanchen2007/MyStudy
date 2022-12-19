### 解题思路
写了一上午，发现公式一直写不对，不说了，菜是原罪。我dtmd，我tm的太菜了呜呜呜。

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        n,c=num_people,candies
        def cal(begin,end):
            if begin>end:
                return 0
            return int(((end+begin)/2)*(end-begin+1))
        p=cal(1,n)
        i=0
        j=0
        re=[0]*n
        need=0
        while True:
            if p+need*n<c:
                c-=(p+need*n)
                need+=n
            else:
                before=need
                for j in range(n):
                    need+=1
                    if need<c:
                        c-=need
                        re[j]+=need
                    else:
                        re[j]+=c
                        return [re[k]+(1+k)*i+n*cal(1,i-1) for k  in range(n)]
            i+=1
```