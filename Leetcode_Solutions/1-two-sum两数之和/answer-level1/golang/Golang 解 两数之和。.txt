小白参考了大神们的解法，自己用Go语言写了一个解法供参考，加深一下对Go的理解,如有错误还望指出。

```
    func twoSum(nums []int, target int) []int {
	m := make(map[int]int)           //make()函数初始化之后才能进行操作
	a := make([]int, 2)
	for i := 0; i < len(nums); i++ {
		key := target - nums[i]
		if value, ok := m[key]; ok { //余数作为key值判断map里是否有对应的value，返回true或false给ok，然后if语句判断ok
			a[0] = value             //若找到，则将map里的value，即数组的下标存入a[0]
			a[1] = i                 //当前数组下标存入a[1]
			break
		}
		m[nums[i]] = i               //将数组里的值作为map里的key值，数组的下标i作为map里的value
	}
	return a
    }
```
执行用时 : 4 ms  （暴力法执行用时更多）
内存消耗 :3.8 MB （暴力法内存消耗更少）


用测试用例推算一下
{5, 3 , 5, 6}
10
```
    func twoSum(nums []int, target int) []int {
	m := make(map[int]int)           
	a := make([]int, 2)
	for i := 0; i < len(nums); i++ {
		key := target - nums[i]       //一、(key：5 ; nums[0] = 5) | 二、(key：7 ; nums[1] = 3)              | 三、(key:5 ; nums[2] = 5)
		if value, ok := m[key]; ok {  //一、 m中无值 , ok = false  |二、 m={5:0}, m[7] 无对应value ok = false | 三、m = {5:0, 3:1}, m[5]对应0 , ok = true
			a[0] = value              //一(二)、跳过. 三、a[0] = 0
			a[1] = i                  //一(二)、跳过. 三、a[1] = 2
			break
		}
		m[nums[i]] = i                //一、m[5] = 0 ; m = {5:0} | 二、m = {5:0, 3:1}
	}
	return a                          //得到答案[0,2]
    }
```
稍微改动一下可减少一次if语句判断：
```
    func twoSum(nums []int, target int) []int {
	m := make(map[int]int)           
	a := make([]int, 2)
    m[nums[0]] = 0                   //预先将第一个值存入map。
	for i := 1; i < len(nums); i++ { //并将i := 0 改为 i := 1 。此做法可减少一次 if 语句判断。
		key := target - nums[i]
		if value, ok := m[key]; ok { 
			a[0] = value             
			a[1] = i                 
			break
		}
		m[nums[i]] = i               
	}
	return a
    }
```
