### 解题思路
两个指针之间不能互相制约，故for的嵌套循环不能用。 确定用while循环。
两个指针的累加条件也不能互相制约，都设置成总和的1/3最清晰。
均为1/3时为true，否则为false。
另外注意，++--的先后

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
    	int sum=0;
    	for (int i = 0; i < A.length; i++) {
			sum+=A[i];
		}
    	if (sum%3!=0) {
			return false;
		}else {
			int left=0;
			int right=A.length-1;
			int sumleft=A[left];
			int sumright=A[right];          //双指针，不能用for的嵌套循环，会互相制约。

			while(left+1<right) {           //直接从总和做文章很清晰，不要用sumleft和sumright比
				if (sumleft==sum/3&&sumright==sum/3) {
					return true;
				}
				if (sumleft!=sum/3) {
					sumleft+=A[++left];    //初始设为0，故应该先++
				}
				if (sumright!=sum/3) {
					sumright+=A[--right];    //初始设为A.length-1，故应该先--
				}
			}
			return false;
		}
    }
}
```