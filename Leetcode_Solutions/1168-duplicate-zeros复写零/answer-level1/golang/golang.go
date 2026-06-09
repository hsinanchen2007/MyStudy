```
func duplicateZeros(arr []int)  {
    for i := 0; i < len(arr); i ++{
        //如果是0且后面有可以复写的地方
        if arr[i] == 0 && i < len(arr) - 1{
        //如果后面有需要后移的东西
            if i < len(arr) - 2{
                arr = append(arr[ : i + 2],arr[i + 1 : len(arr) - 1]...)
            }
            arr[i + 1] = 0
        //跳过复写的0
        i ++
        }
    }
}
```
