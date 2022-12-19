### 解题思路 - 自定义规则进行排序

为了使拼接后的数字尽可能大，一种直观的想法是要使得高位的数字尽量大。

一般化的讨论新的对比规则，假设对比函数是cmp，需要对比的两个字符串是s1和s2。

根据刚才的演示可以把s1和s2的两种拼接结果显示出来。 

- s12 = s1+s2 
- s21 = s2+s1

如果s12 > s21,则s1要放在s2的前面，这样拼接出来的结果才会比较大。

这种方法最耗时的部分是排序。而基于比较的排序算法时间复杂度下界是O(nlogn),

因此这种方法的时间复杂度是O(n*logn),其中n是数组的长度。

我们需要将整数数组转换成字符串数组，因此需要O(n)的辅助空间，空间复杂度是O(n)。

### 代码

```golang
// Time: O(n*log(n)), Space: O(n)
func largestNumber(nums []int) string {
  // 处理边界情况，如果数组为空或长度为0
  if nums == nil || len(nums) == 0 {
    return "" // 返回空的字符串
  }
  // 否则定义一个长度为n的字符串数组
  strs := make([]string, len(nums))
  // 遍历整数数组,把整数转成字符串,并存储到字符串数组
  for i := range nums {
    strs[i] = strconv.Itoa(nums[i])
  }
  // 接下来对字符串进行排序,注意这里要自定义对比规则
  sort.Slice(strs, func(i, j int)bool{
    // 先把两种字符串的拼接结果写出来
    s12 := strs[i]+strs[j]
    s21 := strs[j]+strs[i]
    // 如果字符串s12大于s21，那么我们希望s1排在s2前面。
    return s12>s21
  })
  // 首先检查排序后第0个元素是不是字符串0
  if strs[0] == "0" {
    return "0" // 说明后面都是0，直接返回0即可
  }
  // 把数组中的字符串依次拼接起来
  var buffer bytes.Buffer
  for i := range strs{
    buffer.WriteString(strs[i])
  }
  return buffer.String()
}
```
### 解题思路 - 改进版本
在这种实现中可以看到每次去对比s1和s2时，都需要额外的生成两个字符串s12和s21。

然后再进行对比，事实上s12和s21的对比，就是那s1中的字符和s2中的字符进行对比。

长度不足时再拿后半部分的s2或s1进行对比，因此事实上我们并不需要真正生成s12和s21这两个字符串。

只需要把s1和s2的字符取出进行对比即可。

改进版本，修改以后就不会再排序的过程中产生额外的字符串，因此速度可以得到提升，但是时间复杂度保持不变。

### 代码

```golang
func largestNumber(nums []int) string {
  // 处理边界情况，如果数组为空或长度为0
  if nums == nil || len(nums) == 0 {
    return "" // 返回空的字符串
  }
  // 否则定义一个长度为n的字符串数组
  strs := make([]string, len(nums))
  // 遍历整数数组,把整数转成字符串,并存储到字符串数组
  for i := range nums {
    strs[i] = strconv.Itoa(nums[i])
  }
  // 接下来对字符串进行排序,注意这里要自定义对比规则
  sort.Slice(strs, func(i, j int)bool{
    // 把s1和s2的长度赋值给n1和n2方便使用
    n1, n2 := len(strs[i]), len(strs[j]) 
    // 然后下标从0遍历到n1+n2-1，模拟s12和s21的对比
    for c:=0;c<n1+n2;c++{
      // 模拟从s12取第i个字符的操作
      var c1 byte
      if c < n1 {
        c1 = strs[i][c]
      }else {
        c1 = strs[j][c-n1]
      }
      
      // 模拟从s21取第i个字符的操作
      var c2 byte
      if c < n2 {
        c2 = strs[j][c]
      }else {
        c2 = strs[i][c-n2]
      }
      
      // 对比取出的两个字符
      if c1 == c2 {
        continue
      }
      return c1>c2
    }
    return true
  })
  // 首先检查排序后第0个元素是不是字符串0
  if strs[0] == "0" {
    return "0" // 说明后面都是0，直接返回0即可
  }
  // 把数组中的字符串依次拼接起来
  var buffer bytes.Buffer
  for i := range strs{
    buffer.WriteString(strs[i])
  }
  return buffer.String()
}
```