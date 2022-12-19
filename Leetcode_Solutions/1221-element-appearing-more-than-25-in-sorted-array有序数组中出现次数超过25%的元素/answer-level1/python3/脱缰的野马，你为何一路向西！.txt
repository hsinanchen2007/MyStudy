### 解题思路


### 代码
#### 方法点笨了，
..创建哈希 以数组元素重复次数为值 元素为键 逐个添加 最后遍历字典元素大于数组长度的四分之一则则返回..
```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        #习惯了为自己做题加戏，从而达到一思百应的效果
        #走你
        #抓关键字： 有序 恰好一个 25%
        length = len(arr)
        flag = length/4
        hash = {}
        for i in range(length):
            hash[arr[i]] = hash.get(arr[i],0)+1 
        for k,v in hash.items():
            if v > flag:
                return k
```