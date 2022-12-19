java:
找规律，两边的元素全部是1，因此如果是两边直接设置为1
如果不是两边的则 理解为a[i][j] = a[i-1][j-1]+a[i-1][j]
循环即可
```
class Solution {
    public List<List<Integer>> generate(int numRows) {//杨辉三角，每行除两边外，a[i][j] = a[i-1][j-1]+a[i-1][j]
        List<List<Integer>> arr = new ArrayList<>();
        if (numRows<1) {
			return arr;
		}
        List<Integer> arr1 = new ArrayList<>();
        arr1.add(1);
        arr.add(arr1);//第一行添加0
        for(int i = 1;i<numRows;i++) {
        	List<Integer> arr2 = new ArrayList<>();//每次的内部元素
        	for (int j = 0; j <= i; j++) {
				if(j==0||j==i) {
					arr2.add(1);
				}else {
					int num1 = arr.get(i-1).get(j-1);
					int num2 = arr.get(i-1).get(j);
					arr2.add(num1+num2);
				}
			}
        	arr.add(arr2);
        }
        return arr;
    }
}
```
