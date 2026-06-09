### 解题思路
此处撰写解题思路
其实这个题目总的来说就是让你找出这个数组里面重复数量最多的那个数
我的思路是：
1 定义一个int类型的基本变量用于保存找到的元素
2 使用2个for循环遍历这个数组，用其中每个元素和数组内的所有元素进行比较
3 当比较元素一样时，计数加1
4 当重复数量大于其总长度的25%时候，保存这个数
注意：定义计数的变量要定义在第一for循环下，因为每找完一次就要将计数归零，以便下一次计数

### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        
	  int v= 0;
	    int s = arr.length/4;
	   
	    for (int i = 0; i < arr.length; i++) {
            int sum = 0;
			for (int j = 0; j < arr.length; j++) {
				if(arr[i] ==arr[j]){
					sum++;
                    if(sum>arr.length/4){
                        v = arr[i];
                    }
				}
			}
		}
	   
	    return v;
	    
	    
    }
}
```