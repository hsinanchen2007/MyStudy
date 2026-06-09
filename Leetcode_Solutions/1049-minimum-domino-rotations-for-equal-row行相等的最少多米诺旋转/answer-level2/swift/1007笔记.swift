- ### 解题思路
最开始的思路是检查数组第0位以后的数据和第0位的情况，一样不需要翻转，不一样则对另外一个数组那里查看结果，一样的话翻转数+1，不一样则放弃计算，最后在两个翻转数的取一个最小值
但是发现测试没通过，原因是我默认第0位不翻转，存在情况是需要翻转0位来完成的

### 代码

```swift
class Solution {
    func minDominoRotations(_ A: [Int], _ B: [Int]) -> Int {
    
    var cnt : [Int] = [Int](repeating: 0, count: 4)
    cnt[2]=1
    cnt[3]=1
    let AB = [A,B]
    for i in 1 ..< A.count{
        for j in 0 ..< 2{
            if cnt[j] == -1{
                continue
            }
            if AB[j][i] == AB[j][0]{

            }else if AB[1-j][i] == AB[j][0]{
                cnt[j] = cnt[j] + 1
            }
            else{
                cnt[j] = -1
            }

        }
        for j in 0 ..< 2{
            if cnt[2+j] == -1{
                continue
            }
            if AB[1-j][i] == AB[j][0]{
                
            }else if AB[j][i] == AB[j][0]{
                cnt[2+j] = cnt[2+j] + 1
            }
            else{
                cnt[2+j] = -1
            }
            
        }
        
        
        if cnt[0] == -1 && cnt[1] == -1 && cnt[2] == -1 && cnt[3] == -1{
            return -1
        }
    }
    for i in 0 ..< 4{
        if cnt[i] == -1{
            cnt[i]=Int.max
        }
    }
    return cnt.min()!
    }
}
```