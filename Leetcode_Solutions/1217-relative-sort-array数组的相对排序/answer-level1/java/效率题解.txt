第一次不看评论题解 击败了

执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.83%
的用户
内存消耗 :
35.7 MB
, 在所有 Java 提交中击败了
100.00%
的用户
思路： 1. 创建一个数组长度小于等于1001  = list   
2. 将arr1循环放入到list中arr1中的值作为下标，value为出现的次数
3. 循环arr2，根据对应下标取出value,循环添加当前下标value次，然后将value赋值为0；
4. 循环list，将value值不等于1的循环添加到数组末尾
```
public static int[] relativeSortArray(int[] arr1, int[] arr2) {
		int[] list = new int[1001];
		for (int i = 0; i < arr1.length; i++) {
			list[arr1[i]]++;
		}
		int k = 0;
		for (int i = 0; i < arr2.length; i++) {
			int i1 = list[arr2[i]];
			for (int j = 0; j < i1; j++) {
				arr1[k] = arr2[i];
				k++;
			}
			list[arr2[i]] = 0;
		}
		for (int i = 0; i < list.length; i++) {
			int i1 = list[i];
			for (int j = 0; j < i1; j++) {
				arr1[k] = i;
				k++;
			}
		}
		
		return arr1;
	}
```