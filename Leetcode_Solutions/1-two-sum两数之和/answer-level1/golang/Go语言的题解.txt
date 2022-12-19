看不到go语言的道友们发，我就写一个题解来说明一下，写的不好的地方请大家指出，谢谢！
考虑到go本身就很快，所以直接暴力相加比较。
第一个参数是一个slice，而返回值是一个slice并且我们需要把两个下标放入一个slice里面返回，
var value []int
这时考虑使用遍历去读取slice里面的值，同时也能读到下标：
for i1, v1 := range nums
这是第一个，但是，第一个使用后就没必要使用了，第二层循环可以从第一个下标的后一个开始，所以第二个循环这样写：
for i2 := i1+1; i2<len(nums); i2++
这样写了两个循环之后，就可以每次判断
if target == v1 + nums[i2]
来判断是否相等，如果相等则
value = append(value, i1)
value = append(value, i2)
return value
不要忘记这个方法的最后一行要加一个
return value
保证每一个分支都有返回，测试执行速度是44ms，内存是3MB，
