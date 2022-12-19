看了高票的几个题解，核心思想大家基本是一致的，有些专业的说法说排序+双指针+剪枝，看他们写的细节里面包括代码都有问题，有些用几个嵌套while，虽然有点眼前一亮，但是可读性并不是很好，是很多人包括我自己吐槽的点，仔细想了下其实代码也挺简单的，只是大家术语听起来有点高大上吧，不多说了，这里思想也是如此。

**暴力法**

三重遍历解决，保量结果使用map去重判断，在第311/313个用例超时
```
func threeSum(num []int) [][]int {
 sort.Ints(num)
	isMapExist:=make(map[string]int);
	res :=[][]int{}
	for i:=0;i<len(num);i++ {
		if(num[i] > 0) {
			continue
		}
		for j:=i+1;j<len(num);j++ {
			for z:=j+1;z<len(num);z++  {
				if i!=j && j!=z && i!=z {
					if num[i] + num[j] + num[z] == 0 {
						arr :=[]int{num[i],num[j],num[z]};
						str := strconv.Itoa(num[i]) + "_" +strconv.Itoa(num[j]) + "_" + strconv.Itoa(num[z]) + "_";
						if _,ok := isMapExist[str];ok {
							continue;
						}
						res = append(res,arr)
						isMapExist[str] = 0;
					}
				}
			}
		}
	}
	return res
}
```


**优化后大体思想**

1,排序数组(由小到大)
2,遍历数组，发现当前数值>0,则可以跳过。
3,在当前数组的位置，对后面的数字进行遍历，使用前后俩个角标，一大一小来进行匹配，找到num[i]+num[j]+num[z] = 0,则移动角标，找下一对。
4,因为是顺序遍历的，若是某个数字和之前重复，则说明结果集合已经被算过了。
5,为了防止找出的三个数集合有重复，这里也可以使用一个map判断去重实现，不过我这里的代码是直接把角标再次作了判断。

```
func threeSum(num []int) [][]int {
	sort.Ints(num)
	res :=[][]int{}
	length :=len(num)
	for i:=0;i<length;i++ {
		if (num[i] > 0) {
			continue //当前>0 则不用计算之后的
		}
		if (i>0 && num[i] == num[i-1]) {
			continue //当前重复的元素,之前计算过一次，不必再次计算
		}
		z := length - 1
		for j := i + 1; j < length && z >i && j < z; {
			if(z<length-1 && num[z]==num[z+1]) {
				z--			//去重
				continue
			}
			if(num[j]==num[j-1] && j-1>i) {
				j++        //去重
				continue
			}
			if (num[i]+num[j]+num[z] > 0) {
				z--
			} else if (num[i]+num[j]+num[z] < 0) {
				j++
			} else {
				arr := []int{num[i], num[j], num[z]};
				res = append(res, arr)
				z--;j++
			}
		}
	}
	return res
}
```


