吐槽一下，题目说0 <= arr[i] <= 1000,实际上提交时，验证我的答案的用例大小范围是0 <= arr[i] <= 10000.。。
这道题我的想法来自于编程珠玑那本书。
先创建一个大小为10001的数组line（随便起的名字），默认值是0不用管。
遍历arr，每次将arr[i]的值作为line的下标，然后line[arr[i]]++。这样遍历完后，line这个数组存放的就是arr中每个值存放的次数。如arr=[3,2,1]。那么最后line=[0,1,1,1,0.,0..]，又如arr=[0,1,2,1],则line=[1,2,1,0....]
这样再遍历一次arr就可以了
```
public int[] getLeastNumbers(int[] arr, int k) {
		int length = arr.length;
		int[] out = new int[k];
		if (length == k) {
			return arr;
		}
		if (k == 0) {
			return new int[0];
		}
		int[] line = new int[10001];
		for (int value : arr) {
			line[value]++;
		}
		a:
		for (int i = 0, count = 0; i < length; i++) {
			for (int j = 0; j < line[i]; j++) {
				out[count] = i;
				if (++count == k) {
					break a;
				}
			}

		}
		return out;
```
