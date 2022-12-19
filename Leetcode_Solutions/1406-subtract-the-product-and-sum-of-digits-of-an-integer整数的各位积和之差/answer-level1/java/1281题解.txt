### 解题思路
这道题考察的是如何获取一个自然数各个位置的数字，我们可以使用对10进行求余的方法获取，写一个while循环，判断条件为n>0，将n对10进行求余，结果放入List中，同时n=n/10。

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        List<Integer> list = new ArrayList<>();
		 while(n > 0) {
			 list.add(n % 10);
			 n = n / 10;
		 }
		 
		 int sum = 0;
		 int product = 1;
		 for(int i : list) {
			 sum += i;
			 product = product * i;
		 }
		 
		 return product - sum;
    }
}
```