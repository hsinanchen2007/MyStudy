### 解题思路
我们可以发现, 可以把题目中的数组拆分成两部分, 一部分是负数的数组, 另一部分是非负数数组, 这两个数组都是排好序的,而且他们的元素平方的出来的值也是排好序的; 这样就跟"合并两个有序数组"的题目思路一样了.
1,新建一个数组, 长度跟输入的数组长度相等, 用于存放比较后的元素;
2,我们定义两个指针分别指向数组的第一个元素和最后一个元素, 遍历的时候两个指针向中间移动, 一直到左指针<=右指针才推出;
3,把两个指针指向的元素取出, 计算平方值, 进行比较, 哪个值大就从后往前依次放入新数组中.

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {

        int list[] = new int[A.length];
        int indexCur = A.length-1;

    	int indexLeft = 0;
    	int indexRight = A.length-1;
    	
    	while(indexLeft <= indexRight) {
    		int tempLeft = A[indexLeft];
			int tempLeft2 = tempLeft*tempLeft;
			
			int tempRight = A[indexRight];
			int tempRight2 = tempRight*tempRight;
			if (tempLeft2 <= tempRight2) {
				list[indexCur] = tempRight2;
				indexCur --;
				indexRight--;
			}else if (tempLeft2 > tempRight2) {
				list[indexCur] = tempLeft2;
				indexCur --;
				indexLeft++;
			}
    		
    	}
    	return list;
    }
}
```