思路简单，hash计数，堆输出，直接在方法该方法里面定义堆的各种方法，把堆数组看成全局
```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dict_hash = {}
        for i in nums:
            if i not in dict_hash.keys():
                dict_hash[i] = 1
            else:
                dict_hash[i] += 1
        
        h = [0 for _ in range(len(dict_hash)+10)]
        ph = [0 for _ in range(len(dict_hash)+10)]
        size = len(dict_hash)

        for index,i in enumerate(dict_hash.keys()):
            h[index+1] = dict_hash[i]
            ph[index+1] = int(i)

        def swap(u,t):
            h[u], h[t] = h[t],h[u]
            ph[u], ph[t] = ph[t],ph[u]

        def down(u):
            t = u
            if 2*u <= size and h[2*u]>h[t]: 
                t = 2*u
            if 2*u + 1 <= size and h[2*u + 1] > h[t]: 
                t = 2*u + 1
            if u!=t:
                swap(u,t)
                down(t)
        
        def up(u):
            if u>>1 > 0 and h[u>>1] < h[u]:
                swap(u,t)
                up(u>>1)
        
        for i in range(size>>1,0,-1):
            down(i)

        res = []
        for _ in range(1,k+1):
            res.append(ph[1])
            swap(1,size)
            size -= 1
            down(1)
        return res
```
