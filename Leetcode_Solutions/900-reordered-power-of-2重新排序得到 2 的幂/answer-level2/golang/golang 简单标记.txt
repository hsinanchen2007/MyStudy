由于2的次幂数在1e9的范围内不多（大约30个左右），先将2的次幂的数所需要的1到9的个数先记录下来，再和输入的N的1到9的个数比对下，查找是否有完全相同即可

```go
var arr [30][10]int
var arr2 [10]int

func reorderedPowerOf2(N int) bool {
    //打表 1<<N可以得到2^N次方
    for i:=0;(1<<uint32(i))<=1000000000;i++{
        for j:=0;j<10;j++{
            arr[i][j]=0
        }
		for temp:=1<<uint32(i);temp!=0;temp/=10{
			arr[i][temp%10]++
		}
	}
	for i:=N;i!=0;i/=10{
		arr2[i%10]++
	}
        //比对
	for i:=0;i<30;i++{
        flag := 1
		for j:=0;j<10;j++{
			if arr2[j]!=arr[i][j]{
				flag=0
				break
			}
		}
		if flag == 1{
			return true
		}
	}
	return false
}
```