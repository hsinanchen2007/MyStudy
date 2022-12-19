思路，以[90,100,56,10,0,80,30,60]为例：
1. 降序数组，数组内容为值及对应的原始位置（location，value）[(1,100),(0,90),(5,80),(7,60),(2,56),(6,30),(3,10),(4,0)]
2. 遍历排序后的数组，根据能够接水的必要条件是两个柱子之间必须有间隙，即不能相邻，拿到可以接水的区间:
    - 100跟90之间没有间隙，找下一个；
    - 100跟80之间有间隙，符合可以接水的必要条件，存储该区间gap =（1，5），并计算该区间可以接水的量:遍历区间（2～4）内的数据container += min(100,80) - arr[i];
    - 继续循环，看是否在gap区间对应（0，6）范围内（其中0和6，如果在，由于已经计算，continue），80不再区间，根据位置关系更新gap为（1，7），计算新增区间（5，7）可以接水的量container += min(100,80) - arr[i]；
    - 比较gap区间跟整个数组范围（1，count -2）关系，如果小于等于gap，计算完毕，没有继续c步骤。
![思路.png](https://pic.leetcode-cn.com/c8b68044a1602ba24e125b16af295605c03e03dc2aa7c31eba65139f31dc1483-image.png)
```
func trap(_ height: [Int]) -> Int {
    if height.count <= 2 {
        return 0
    }
    let sortHeight = sortArr(arr: height)///降序，拿到值及对应的原始位置 [(原始位置，值)]
    
    var container = 0
    var gap :(Int,Int)?
    
    for k in 0..<sortHeight.count-1 {
        let firstL = sortHeight[k]
        guard let gugap = gap else {
            var i = k+1
            
            while (gap ?? nil) == nil && i < sortHeight.count{///从最大值（如果不是最大值开始，可能漏算）开始，拿到第一段可以接水的区间。
                let secondL = sortHeight[i]
                if abs(firstL.0 - secondL.0) > 1 { ///可以接水的必要条件是，两个柱子之间有间隙
                    let start = min(secondL.0, firstL.0)
                    let end = max(secondL.0, firstL.0)
                    gap = (start,end)///保存区间
                    for g in start + 1...end-1 {///计算此区间可以接水的量
                        container += secondL.1 - height[g] < 0 ? 0:secondL.1 - height[g]///虽然中间有间隔，但是不能保证能接水，去掉不能接水，即中间的柱子不是最小
                        
                    }
                    if start <= 1 && end >= sortHeight.count - 2{
                        return container
                    }
                }
                i += 1
            }
            continue
        }
        if firstL.0 <= gugap.1 + 1 && firstL.0 >= gugap.0 - 1  {///在已经结算的区间内，continue
            continue
        }else{///不再已经结算的区间，根据位置关系，更新结算区间
            var start = 0
            var end  = 0
            if firstL.0 > gugap.1 {///在右边
                start = gugap.1
                end = firstL.0
                gap = (gugap.0,end)
            }else{///在左边
                start = firstL.0
                end = gugap.0
                gap = (start,gugap.1)
            }
            for g in start + 1...end-1 {///计算新增区间可以接水的量，同样可能会有不能接水的可能，剔除
                container += firstL.1 - height[g] < 0 ? 0:firstL.1 - height[g]
                
            }
            if start <= 1 && end >= sortHeight.count - 2{
                return container
            }
        }
    }
    return container
}
 func sortArr(arr:[Int]) -> [(Int,Int)] {///希尔排序
    let count = arr.count
    var locValueTump :[(Int,Int)] = []
    for i in 0..<count {
        locValueTump.append((i,arr[i]))///记录位置及对应的值
    }
    
    var gap = count/2
    while gap > 0 {
        for i in gap..<count{
            var j = i
            let temp = locValueTump[j]
            if locValueTump[j].1 > locValueTump[j-gap].1 {
                while j-gap>=0 && temp.1 > locValueTump[j-gap].1 {
                    locValueTump[j] = locValueTump[j-gap]
                    j -= gap
                }
                locValueTump[j] = temp
            }
        }
        gap /= 2
    }
    
    return locValueTump
}
```


