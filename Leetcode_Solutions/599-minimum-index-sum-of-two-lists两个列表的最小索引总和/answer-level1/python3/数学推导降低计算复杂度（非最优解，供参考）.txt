### 解题思路
该方法充分应用数学推到。非最优解，仅供参考。
假定索引和sumi为正确解，则存在队列1的某个索引为sumj的元素与队列2的某个索引为sumi-sumj的元素相等。
我们不知道sumi和sumj是多少，所有使用循环遍历sumi和sumj找到最终解。
且满足sumi属于（0，len1+len2）
sumj属于（0，len1）
sumi-sumj属于（0，len2）
可以推导出sumj属于（max(sumi-len(list2)+1,0),min(len(list1),sumi+1)）。
计算复杂度比len1*len2缩小不少
### 代码

```python3
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        rst=[]
        for sumi in range(len(list1)+len(list2)-1):
            if rst!=[]:return rst
            else :
                for sumj in range(max(sumi-len(list2)+1,0),min(len(list1),sumi+1)):
                    if list1[sumj]==list2[sumi-sumj]:rst.append(list1[sumj]) 
        return rst
```