### 解题思路
单纯为了练手堆排序，事件复杂度不小，如果想了解堆排序解法地伙伴可以参考，堆排序具体思路如下：
1.将无序序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆
2.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端
3.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序。

### 代码

```java
class Solution {
    public int[] subSort(int[] array) {
		//创建一个和传入数组一样地数组，用于后面地比对
        int[] arr = new int[array.length];
		for(int a = 0; a< array.length;a++) {
			arr[a] = array[a];
		}
		//调整成为一个大顶堆
		int temp = 0;
		for(int i = arr.length / 2 - 1; i>=0 ;i--) {
			adjustHeap(arr,i,arr.length);
		}
		//沉淀最大元素+调整大顶堆
		for(int j = arr.length - 1;j> 0;j--) {
			temp = arr[j];
			arr[j] = arr[0];
			arr[0] = temp;
			adjustHeap(arr,0,j);
		}
		//创建一个包含返回区间的含两个元素的数组
		int[] result = new int[2];
		result[0] = 0;
		result[1] = array.length-1;
		//从头遍历找出需要排序区间的左边界
		for(; result[0] < array.length;result[0]++) {
			if(arr[result[0]] != array[result[0]]) break;
		}
		//从尾遍历找出需要排序区间的右边界
		for(; result[1] >=0;result[1]--) {
			if(arr[result[1]] != array[result[1]]) break;
		}
		//如果左边界大于等于右边界，说明序列已经有序
		if(result[0] >= result[1]) {
			result[0] = -1;
			result[1] = -1;
		}
		//返回结果含取键边界值的数组
		return result;
    }
    private static void adjustHeap(int[] arr, int i, int length) {
		int temp = arr[i];// 先取出当前元素的值，保存在临时变量
		for(int k = i * 2 + 1; k<length;k = k * 2 + 1) {
			if(k + 1 < length && arr[k]<arr[k+1]) {
				k++;
			}
			if(arr[k] > temp) {
				arr[i] = arr[k];
				i = k;// i 指向 k,为了后面的temp的值可以赋给对应的arr[i]，从而避免了起初的arr[i]的值的丢失
			}else {
				break;//这种情况下说明下面地不需要在调整了，已经有序。所以每次在将数组形成大顶堆的时候要从下往上调整
			}
		}
		arr[i] = temp;// 将temp值放到调整后的位置
	}
}
```