### 解题思路
1 创建hash表 key 当前已经被遍历的数据值 value 是当前值的位置
2 遍历列表
3 通过相减获取我们要查找的另外一个值
4 判断是不是在当前的hash 表中
5 不在就把当前值作为key 索引位置作为value


### 代码

```golang
func twoSum(nums []int, target int) []int {
	m := make (map[int]int)// key 当前已经被遍历的数据值 value 是当前值的位置
	for i,v :=range nums{
		k := target-v // 通过相减获取我们要查找的另外一个值
		if l,ok:=m[k];ok {// 判断是不是在当前的hash 表中
			return []int{l,i}
		}else {
			m[v]= i // 不在就把当前值作为key 索引位置作为value
		}
	}
	return nil
}

```