### 解题思路
**现在只想问：为什么java的不是返回list呀**
好啦：我的思想很简单，就是暴力。
当然我们从数学上思考知道 2*half = number，所以当只有两个连续的数相加时，一个<half，一个>half，所以起始数小于half的

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<List<Integer>> list = new ArrayList<>();
		
		int length=0;//有几个这样的数组
		int sum=0;
		
		for (int i = 1; i <= (target-1)/2; i++) {
			List<Integer> temp = new ArrayList<>();
			for (int j = i; ; j++) {
				sum+=j;
				temp.add(j);
				if(sum>target) {
					sum = 0;
					temp.clear();
					break;
				}
				if(sum==target) {
					length++;
					list.add(temp);
					break;
					
				}
			}

		}

		int k=0;
		int[][] arr = new int[length][];
		for(List<Integer> l:list) {
			arr[k] = new int[l.size()];
			for (int i = 0; i < l.size(); i++) {
				arr[k][i] = l.get(i);
			}
			k++;
		}
		System.out.println(Arrays.deepToString(arr));
		return arr;
    }
}
```