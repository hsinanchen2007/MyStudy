### 解题思路
递归和动态规划不断优化的几个版本

### 代码

```golang
func climbStairs(n int) int {
    return robot(n)
}
//递归
// func robot(n int)int{
//     if n==0{
//         return 1
//     }
//     if n<0{
//         return 0
//     }
//     return robot(n-1)+robot(n-2)
// }

//递归带中间缓存优化
// func robot(n int,tmp []int)int{
//     if n==0{
//         return 1
//     }
//     if n<0{
//         return 0
//     }
//     if tmp[n]>0{
//         return tmp[n]
//     }
//     k:=robot(n-1,tmp)+robot(n-2,tmp)
//     tmp[n]=k
//     return k
// }

//动态规划I
// func robot(n int)int{
//     tmp:=make([][]int,n+1)
//     for i:=0;i<n+1;i++{
//         tmp[i]=make([]int,2)
//     }
//     if n==1{
//         return 1
//     }
//     if n==2{
//         return 2
//     }
//     tmp[1][0]=1
//     tmp[1][1]=0
//     tmp[2][0]=1
//     tmp[2][1]=1
//     for i:=3;i<=n;i++{
//        tmp[i][0]=tmp[i-1][0]+tmp[i-1][1]
//        tmp[i][1]=tmp[i-2][0]+tmp[i-2][1]
//     }
//     return tmp[n][0]+tmp[n][1]
// }
//动态规划II，滚动数组
// func robot(n int)int{
//     tmp:=make([][]int,2)
//     for i:=0;i<2;i++{
//         tmp[i]=make([]int,2)
//     }
//     if n==1{
//         return 1
//     }
//     if n==2{
//         return 2
//     }
//     tmp[0][0]=1
//     tmp[0][1]=0
//     tmp[1][0]=1
//     tmp[1][1]=1
//     for i:=2;i<n;i++{
//        tmp[i%2][1]=tmp[i%2][0] + tmp[i%2][1]
//        if i%2==0{
//            tmp[i%2][0]=tmp[i%2+1][0]+tmp[i%2+1][1]
//        }else{
//            tmp[i%2][0]=tmp[i%2-1][0]+tmp[i%2-1][1]
//        }
    
//     }
//      a:=tmp[0][0]+tmp[0][1]
//      b:=tmp[1][0]+tmp[1][1]
//      if a>b{
//          return a
//      }else{
//          return b
//      }
// }
//动态规划III
func robot(n int)int{
 if n == 1 {
    	return 1
	}
    if n == 2 {
    	return 2
	}
    a, b := 1, 2
    for i := 3; i < n; i++ {
		a, b = b, a+b
	}
    return a + b
}
```