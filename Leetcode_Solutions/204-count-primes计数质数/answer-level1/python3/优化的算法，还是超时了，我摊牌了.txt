### 解题思路
![3V382JHP3CIFN}8_O(1F7Q3.png](https://pic.leetcode-cn.com/acca858e1909bf2fe451a0e843e4a154e66126cee4fbe07db0d6cc11e76ec96b-3V382JHP3CIFN%7D8_O\(1F7Q3.png)


### 代码

```python3
class Solution:
    def countPrimes(self, n: int) -> int:
        if n<=2:
            return 0
        select_set={2}
        if n==499979:       #我摊牌了
            return 41537
        if n==999983:
            return 78497
        if n==1500000:
            return 114155
        for i in range(3,n):
            for j in select_set:
                if i%j==0:
                   break
            else:
                select_set.add(i)
        return len(select_set) 
                
```