### 解题思路
	// 思路：
	// 如果想把某个数移到你想到的位置，分两步：
	// 如：[3,2,4,1] 把4移动到最后面
	// k=3 --》把4移动到首位
	// k=4 --》把4移动到最后
	// 因此从i=A.length()-1开始，依次挑选最大的元素放在i位置

### 代码

```java
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        
    List<Integer> list=new ArrayList<Integer>();
		for(int i=A.length-1;i>0;i--) {
			int index=max_index(A,i);
            if (index > 0) {
				reverse(A, index);
				list.add(index + 1);
			}
			reverse(A,i);
			list.add(i+1);
		}
		
		return list;
		
		


	}

	private void reverse(int[] a, int index) {
		for(int i=0;i<=index/2;i++) {
			int tmp=a[i];
			a[i]=a[index-i];
			a[index-i]=tmp;
		}
		
	}

	private int max_index(int[] a,int i) {
		int index=0;
		for(int k=1;k<=i;k++) {
			if(a[k]>a[index]) {
				index=k;
			}
		}
		return index;
	}
}
```