### 解题思路
参考其他大牛的代码和思路，尝试了两种写法的快速排序，两种写法的桶排序，以及基数排序
### 代码

```golang
func sortArray(nums []int) []int {
	//fastSort(nums,0,len(nums)-1)
	//return nums

	//quicksort(nums,0,len(nums)-1)
	//return nums

	//return bucketSort(nums)

	//return bucketSort1(nums)

	return radixSort(nums)
}

//========基数排序==============
func radixSort(nums []int) []int {
	numsWithUnitSlice,q := initObjAndGetMaxUnitNum(nums)
	for i := 1; i <= q; i++ {
		for j, v := range numsWithUnitSlice {
			v.unit = getUnitNum(i, v.nums)
			numsWithUnitSlice[j] = v
		}
		bucketSortOfSpecial(numsWithUnitSlice)//每一位进行桶排序
	}
	for i, unit := range numsWithUnitSlice {//结果输出
		nums[i] = unit.nums
	}
	return nums
}

func initObjAndGetMaxUnitNum(nums []int) ([]numsWithUnit,int) {
	numsWithUnitSlice := make([]numsWithUnit, len(nums))
	max, min := nums[0], nums[0]
	for i, num := range nums {
		numsWithUnitSlice[i] = numsWithUnit{nums: num}
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}
	q := int(math.Log10(float64(max))) + 1 //计算数字有多少位
	if qMin := int(math.Log10(math.Abs(float64(min)))) + 1; q < qMin {
		q = qMin
	}
	return numsWithUnitSlice,q
}
type numsWithUnit struct {
	nums int
	unit int
}
func bucketSortOfSpecial(numsWithUnitSlice []numsWithUnit) {
	min, max := -9, 9
	bucketNum := max - min + 1
	bucket := make([][]numsWithUnit, bucketNum)
	defLen := len(numsWithUnitSlice)/bucketNum + 1
	for _, v := range numsWithUnitSlice {
		tslice := bucket[v.unit-min]
		if tslice == nil {
			tslice = make([]numsWithUnit, 0, defLen)
		}
		tslice = append(tslice, v)
		bucket[v.unit-min] = tslice
	}
	t := 0
	for i := 0; i < bucketNum; i++ {
		if j := bucket[i]; len(j) > 0 {
			for k := 0; k < len(j); k++ {
				numsWithUnitSlice[t] = j[k]
				t++
			}
		}
	}
	//fmt.Println(numsWithUnitSlice)
}

//获取十进制的每一位的值
func getUnitNum(index int, num int) int {
	m:= 9
	for ;index>0;index--{
		m= num%10
		num = num/10
	}
	return m
}

//========桶排序 1 ==============
func bucketSort1(nums []int) []int {
	min, max := rangeOfNum1(nums)
	bucketNum := max - min + 1
	bucket := make([]int, bucketNum)
	for _, v := range nums {
		bucket[v-min] += 1
	}
	t := 0
	for i := 0; i < bucketNum; i++ {
		if j := bucket[i]; j > 0 {
			v := i + min
			for ; j > 0; j-- {
				nums[t] = v
				t++
			}
		}
	}
	return nums
}
func rangeOfNum1(nums []int)(min,max int){
	min,max = nums[0],nums[0]
	for _,v := range nums{
		if min>v{
			min =v
		}
		if max<v{
			max =v
		}
	}
	return
}
//========桶排序  ==============
func bucketSort(nums []int) []int {
	defBoxLen := 10
	min, max := rangeOfNum(nums)
	boxCount := boxNum(nums, defBoxLen)
	rangeOfBox := (max - min +1) / boxCount//这里+1 为了处理max=min，即长度为1的情况
	boxCount = reviseBoxCount(max, min, boxCount, rangeOfBox)
	boxArray := make([][]int, boxCount)
	for _, v := range nums {
		boxIndex := calculateBox(v, min, rangeOfBox)
		tbox := findTheBox(boxArray, boxIndex, defBoxLen)
		tbox = append(tbox, v)
		boxArray[boxIndex] = tbox
	}
	t := combine(nums, boxArray)
	//fmt.Println(t)
	return t
}

func reviseBoxCount(max int, min int, boxCount int, rangeOfBox int) int {
	if i := (max - min) % boxCount; i != 0 { //盒子装不下的数，需要新增盒子
		boxCount += i/rangeOfBox + 1
	} else {
		boxCount += 1 //最大值放到下一个盒子
	}
	return boxCount
}

func findTheBox(boxArray [][]int, boxIndex int, defBoxLen int) []int {
	tbox := boxArray[boxIndex]
	if tbox == nil {
		tbox = make([]int, 0, defBoxLen)
	}
	return tbox
}

func boxNum(nums []int, defBoxLen int) int {
	boxCount := len(nums) / defBoxLen
	if boxCount == 0 {
		boxCount = 1
	}
	return boxCount
}

func combine(nums []int, boxArray [][]int) []int {
	t := make([]int, 0, len(nums))
	for _, v := range boxArray {
		quickSort(v, 0, len(v)-1)
		t = append(t,v...)

	}
	return t
}
func quickSort(nums []int,left,right int){
	if left>=right{
		return
	}
	index := partition2(nums,left,right)
	quickSort(nums,left,index-1)
	quickSort(nums,index+1,right)
}
func partition2(nums []int, left,right int) int{
	pivot := nums[left]
	i,j:=left,right
	for i!=j{
		for i<j&&pivot<=nums[j]{
			j--
		}
		for i<j&&pivot>=nums[i]{
			i++
		}
		if i<j{
			nums[j],nums[i] = nums[i],nums[j]
		}
	}
	nums[i],nums[left] = nums[left],nums[i]
	return i
}
func calculateBox(v ,min,rangeOfBox int) int{
	return (v - min) / rangeOfBox
}

func rangeOfNum(nums []int)(min,max int){
	min,max = nums[0],nums[0]
	for _,v := range nums{
		if min>v{
			min =v
		}
		if max<v{
			max =v
		}
	}
	return
}


//========快速排序 1 ==============
func quicksort(nums []int, left int, right int){
	if left >= right {
		return
	}
	index := partition1(nums,left,right)

	quicksort(nums,left,index-1)
	quicksort(nums,index+1,right)
}
func partition1(nums[] int, left int, right int) int{
	i := left
	j := right
	for i != j{
		for i < j && nums[j] >= nums[left]{
			j --
		}
		for i < j && nums[i] <= nums[left]{
			i ++
		}
		if i < j{
			nums[i],nums[j] = nums[j],nums[i]
		}
	}
	nums[left],nums[i] = nums[i],nums[left]
	return i
}

//========快速排序  ==============
func fastSort(nums []int,s,e int){
	if s>=e{
		return
	}
	q:= partition(nums,s,e)
	fastSort(nums,s,q-1)
	fastSort(nums,q+1,e)
}
//return index of pivot
func partition(nums []int,s,e int) int{
	pivot := nums[e]
	i :=s
	for j:=s;j<e;j++{
		if nums[j]< pivot{
			nums[i],nums[j] = nums[j],nums[i]
			i++
		}
	}
	//nums[i],pivot = pivot,nums[i]
	// pivot 是指针，交换让pivot指针变更和nums[i]指针指向一样，但是pivot原来指向的nums[e]指针值没有变化
	nums[i],nums[e] = nums[e],nums[i]
	return i
}
```