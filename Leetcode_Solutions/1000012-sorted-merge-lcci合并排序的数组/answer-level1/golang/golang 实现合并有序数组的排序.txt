解题思路： 将B切片的元素逐个和A切片的最后一个元素开始比较. 若B元素的值大于A元素，则将B元素放在A元素的后面，并结束A切片的轮询；否则就将A当前元素后移到一位，把B切片的元素放在A当前元素的位置。 还要注意一个临界值的情况，就是当m=0时。

func merge(A []int, m int, B []int, n int)  {
 
    for kb,vb := range B {
		if m > 0 {
			for ka:=m+kb-1; ka>=0; ka-- {
				if vb < A[ka] {
					A[ka+1] = A[ka]
					A[ka] = vb
				} else {
					A[ka+1] = vb
					break
				}  
			}
		} else {
			A[kb] = vb
		}
        		                               
	}
	
}

执行用时 :
0 ms 

内存消耗 :
2.3 MB

在所有 Go 提交中击败了100.00%的用户