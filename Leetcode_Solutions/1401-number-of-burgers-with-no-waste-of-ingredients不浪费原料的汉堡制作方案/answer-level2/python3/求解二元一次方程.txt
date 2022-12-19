
基本思路：求解二元一次方程组
① 4 jumbos + smalls = tomato_slices 
② 2 jumbos + smalls = cheese_slices

```python []
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        a, b = tomatoSlices, cheeseSlices  # 用a, b代替tomatoSlices, cheeseSlices方便书写
        jumbos = (a-2*b)/2  # 根据方程组反算出jumbos和smalls
        smalls = (4*b-a)/2
        if jumbos >= 0 and jumbos == int(jumbos) and smalls >= 0 and smalls == int(smalls):  # 检查jumbos和smalls是非负整数
            return [int(jumbos), int(smalls)] # 如果jumbos和smalls是非负整数，return 结果
        return []  # 否则return []
```

