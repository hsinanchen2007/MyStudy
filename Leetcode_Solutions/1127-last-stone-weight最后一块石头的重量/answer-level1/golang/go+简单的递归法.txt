写完以后才知道go也有快速排序...

```
func lastStoneWeight(stones []int) int {
	if(len(stones)==1){
		return stones[0]
	}

	for i:=len(stones)-1;i>=0 ;i--  {
		BubbleSort(stones)
		stones[len(stones)-1]=(stones[len(stones)-1]-stones[len(stones)-2]);

		stones[len(stones)-2]=0;
	}
	return stones[len(stones)-1]

}
func BubbleSort(arr []int) {
	length := len(arr)
	for i := 0; i < length-1; i++ {
		flag := true //若为true，则表示此次循环没有进行交换，也就是待排序列已经有序
		for j := 0; j < length-1-i; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
				flag = false
			}
		}
		if flag {
			break
		}
	}
}
```
