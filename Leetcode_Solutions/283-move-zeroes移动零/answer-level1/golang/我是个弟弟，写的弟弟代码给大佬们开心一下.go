脑子抽风，死活就要搞个冒泡。还“灵机一动”把第一次遇到的零和冒泡中遇到的零合起来变换成大泡继续冒。
虽然过了，但是代码写的像坨shit。
看了最快代码5555，我什么时候写算法也能想的这么优雅呢，本质都是合起来继续冒嘛为什么我就写成这种样子。

```
func moveZeroes(nums []int)  {
    if len(nums) <= 1{
        return 
    }
    length := 0
    begin := 0
    for i:=0;i<len(nums);i++{
        fmt.Println(i)
        if begin + length >= len(nums) {
                return
            }
        if length == 0{
            if nums[i] != 0{
                continue
            }
            length = 1
            begin = i
            
        } else {
            if nums[begin+length] != 0{
            nums[begin] = nums[begin + length]
            nums[begin+length] = 0
            begin ++
            
            i = begin + length -1
            // fmt.Println(nums, i, begin, length)
        } else {
            length ++
            if begin + length >= len(nums) {
                return 
            }
        }
        }
        
        
    }
}
```
