### 解题思路
使用四个数组分别记录：
1、key
2、value
3、使用频率
4、使用的先用顺序（时间毫秒数可能相同，所以使用全局计数器counter实现）

### 代码

```java
class LFUCache {
private int[] keyArr;
	private int[] valArr;
	private int[] useArr;
	private long[] counterArr;
	private long counter;

	public LFUCache(int capacity) {
		keyArr = new int[capacity];
		valArr = new int[capacity];
		useArr = new int[capacity];
        counterArr = new long[capacity];
		Arrays.fill(keyArr, -1);
	}

	public int get(int key) {
		int index = search(keyArr, key);
		if (index == -1) {
			return -1;
		} else {
			useArr[index]++;
			counterArr[index] = ++counter;
			return valArr[index];
		}
	}

	public void put(int key, int value) {
		if (keyArr.length == 0) {
			return;
		}
		int index = search(keyArr, key);
		if (index == -1) {
			int zeroIndex = search0(keyArr);
			if (zeroIndex == -1){
				int lessUseIndex = searchLessUse();
				keyArr[lessUseIndex] = key;
				valArr[lessUseIndex] = value;
				useArr[lessUseIndex] = 1;
				counterArr[lessUseIndex] = ++counter;
			} else {
				keyArr[zeroIndex] = key;
				valArr[zeroIndex] = value;
				useArr[zeroIndex] = 1;
				counterArr[zeroIndex] = ++counter;
			}
		} else {
			valArr[index] = value;
			useArr[index]++;
			counterArr[index] = ++counter;
		}
	}

	private int searchLessUse() {
		int minIndex = 0;
		for (int i = 1; i < useArr.length; i++) {
			if (useArr[minIndex] > useArr[i]) {
				minIndex = i;
			} else if (useArr[minIndex] == useArr[i]) {
				minIndex = counterArr[minIndex] > counterArr[i] ? i : minIndex;
			}
		}
		return minIndex;
	}

	private int search0(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == -1){
				return i;
			}
		}
		return -1;
	}

	private int search(int[] arr, int value) {
		int index = -1;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == value) {
				index = i;
				break;
			}
		}
		return index;
	}
    
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```