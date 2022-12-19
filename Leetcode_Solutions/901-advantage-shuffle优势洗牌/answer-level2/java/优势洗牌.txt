# 算法分析
此题类似于`田忌赛马`
先对A、B数组排序，l1、l2指向数组第一个值，r1、r2指向数组最后一个值，然后开始比较它们的值。

当A[r1] > B[r2]时，这两个值匹配，因为此时A[r1]不仅能击败B[r2]还能把B中最大的值消耗掉。

当A[r1] < B[r2]时，因为A中的值都无法击败B[r2],索性就把最小的值A[l1]跟B[r2]匹配好了，反正不能赢，减少损失。

当A[r1] == B[r2]时，分两种情况:
1. 当A[l1] > B[l2]时，这两个值匹配。
2. 否则，A[l1] 与 B[r2] 匹配。因为当A[l1] < B[l2]时，A[l1]必输，所以A[l1]跟最大值B[r2]匹配。当A[l1] == B[l2]时，A[l1]还是无法赢，跟B[r2]匹配之后，A[r1]可以跟后面比较小的数字匹配获得胜利。
---------------------------------------------------------------
# 代码
因为B数组排序之后打乱了之前的顺序，所以要存储B排序之前的顺序。
```
class Temp implements Comparable<Temp >{
	int num, index; //存储B数组的值和下标
	public Temp(int num, int index) {
		this.index = index;
		this.num = num;
	}
	@Override
	public int compareTo(Temp o) {
		return this.num - o.num;
	}
}
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
    	Temp[] arr = new Temp[B.length];
    	for(int i = 0; i < B.length; ++i) {
    		arr[i] = new Temp(B[i], i);
    	}
    	Arrays.sort(A); Arrays.sort(arr);
    	int l1 = 0, r1 = A.length - 1;
    	int l2 = 0, r2 = B.length - 1;
    	//B数组的值都保存在arr了，现在的B可以存放答案。
    	while(l1 <= r1) {
    		if(A[r1] > arr[r2].num) {
    			B[arr[r2].index] = A[r1];
    			--r1; --r2;
    		}
    		else if(A[r1] < arr[r2].num) {
    			B[arr[r2].index] = A[l1];
    			--r2; ++l1;
    		}
    		else {
    			if(A[l1] > arr[l2].num) {
    				B[arr[l2].index] = A[l1];
    				++l1; ++l2;
    			}
    			else {
    				B[arr[r2].index] = A[l1];
    				--r2; ++l1;
    			}
    		}
    	}
        return B;
    }
}
```

