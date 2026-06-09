```
/*
1. 对arr1建立哈希表（用map）
2. 对arr2中每个元素，取出哈希表中对应int数组
3. 找出哈希表中value为空数组的key，对keys排序
*/

func relativeSortArray(arr1 []int, arr2 []int) []int {
    var result []int
    
    arr1map := intArr2Map(arr1)
    for _, value := range arr2 {
        
        result = mergeArr(result, arr1map[value])
        arr1map[value] = []int{}
    }
    
    var noOneArr []int
    for _, tmpArr := range arr1map {
        if len(tmpArr) != 0 {
            noOneArr = mergeArr(noOneArr, tmpArr)
        }
    }
    
    
    sort.Ints(noOneArr)
    result = mergeArr(result, noOneArr)
    return result
    
}

func mergeArr(arr1 []int, arr2 []int) []int {
    length := len(arr2)
    for i:=0; i<length; i++ {
        arr1 = append(arr1, arr2[i])
    }
    return arr1
}

func intArr2Map(arr []int) map[int][]int {
    
    dict := make(map[int][]int)
    for _, value := range arr {
        
        dict[value] = append(dict[value], value)
        
    }
    
    return dict
}
```
