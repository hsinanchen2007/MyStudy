![image.png](https://pic.leetcode-cn.com/612459c050ec13fd69214faf47c305fc45a26021d653619f41edb173e88a41a2-image.png)

```
func depthSumN(nestedList []*NestedInteger, dep int) int {    
    if len(nestedList) == 0 {
        return 0
    }
    sum := 0
    for _, v := range nestedList {
        if v.IsInteger() {
            sum += v.GetInteger()*dep
        } else {
            sum += depthSumN(v.GetList(), dep+1)
        }
    }
    return sum
}
func depthSum(nestedList []*NestedInteger) int {
    return depthSumN(nestedList, 1)
}
```
