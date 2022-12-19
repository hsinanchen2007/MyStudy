要点：
1. 外层遍历每个点 i，内层遍历并计算其他点 j 到 i 的距离并通过 Map 保存相等距离的频次
2. 计算距离公式不用开根号
3. 计算排列组合公式 n * (n - 1)

```javascript []
var numberOfBoomerangs = function(points) {
  let res = 0;
  for(let i = 0; i < points.length; i++) {
    // points[i] 设置为枢纽点
    // 记录其他点到points[i]之间的距离的频次
    const map = new Map();
    for (let j = 0; j < points.length; j++) {
      if (j != i) {
        // 以两点距离为key
        const d = dis(points[i], points[j]);
        if (map.has(d)) {
          map.set(d, map.get(d) + 1);
        } else {
          map.set(d, 1);
        }
      }
    }
    // 计算频次的组合
    map.forEach((val, key) => {
      res += val * (val - 1);// 计算排列组合个数 n * (n - 1)
    });
  } 
  return res;
};

function dis(pa, pb) {
  // 求坐标点间的距离 https://baike.baidu.com/item/%E4%B8%A4%E7%82%B9%E9%97%B4%E8%B7%9D%E7%A6%BB%E5%85%AC%E5%BC%8F
  return (pa[0] - pb[0]) * (pa[0] - pb[0]) + (pa[1] - pb[1]) * (pa[1] - pb[1]);
}
```
```python []
class Solution:
    def dis(self, p1, p2):
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])
    
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        res = 0
        for i in points:
            freqMap = {}
            for j in points:
                if j != i:
                    d = self.dis(i, j)
                    freqMap[d] = freqMap[d] + 1 if d in freqMap else 1
            
            for v in freqMap.values():
                res += v * (v - 1)
        
        return res
                        
```
```swift []
class Solution {
  func dis(_ p1: [Int],_ p2: [Int]) -> Int {
    let a = (p1[0] - p2[0]) * (p1[0] - p2[0])
    let b = (p1[1] - p2[1]) * (p1[1] - p2[1])
    return  a + b 
  }
  func numberOfBoomerangs(_ points: [[Int]]) -> Int {
    var res = 0
    for i in points {
      var freqMap:[Int: Int] = [:]
      for j in points {
        if i != j {
          let d = dis(i, j)
          if freqMap[d] != nil {
            freqMap[d]! += 1
          } else {
            freqMap[d] = 1
          }
        }
      }
      for v in freqMap.values {
        res += v * (v - 1)
      }
    }
    return res
  }
}
```
