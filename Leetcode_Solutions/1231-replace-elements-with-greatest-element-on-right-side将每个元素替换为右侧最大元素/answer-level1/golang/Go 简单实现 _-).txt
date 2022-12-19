1. 初始 ```max``` 为最后一个元素
2. 倒序遍历数组，每轮：
    - 先保存当前数组元素到 ```cur```
    - 然后把当前数组元素更新成 ```max```
    - 最后比较并更新 ```max```
3. 设置最后一个元素为 -1


代码如下：
```
func replaceElements(arr []int) []int {
    n := len(arr)
    max := arr[n-1]
    for i := n-2; i >= 0; i-- {
        cur := arr[i]
        arr[i] = max
        if max < cur {
            max = cur
        }
    }
    
    arr[n-1] = -1
    
    return arr
}
```

- 时间复杂度为```O(n)```
- 空间复杂度为 ```O(1)```