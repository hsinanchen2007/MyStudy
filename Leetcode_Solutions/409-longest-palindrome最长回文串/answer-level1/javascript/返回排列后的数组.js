妈的看错题了，返回了排列后的数组，用的方法巨蠢无比
```
    let arr = s.split('')
    if(arr.length === 1) return 1
    arr.sort()
    let stack= []
    let ifasdas = 0
    let i = 1
    while(i<arr.length){
        if(ifasdas === 0&&arr[i-1]!==arr[i]){
            stack.push(arr[i-1])
            ifasdas++
        }
        if(arr[i-1]===arr[i]){
            stack.push(arr[i])
            stack.unshift(arr[i])
            i = i+2
        }else{
            i++
        }
    }
    if(ifasdas === 0 && arr.length % 2 !== 0)return stack.length+1
    return stack.length
```
