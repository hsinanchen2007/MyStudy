![2020011401.PNG](https://pic.leetcode-cn.com/10f1d2cab74ce14aad7a1627f9346981c8b2b85b12f6997b2cb3154396ce643d-2020011401.PNG)

### 解题思路
基于由于是对等位置交换数字,
解题思路---利用冒泡排序思想,每次先找到未在正确位置的最大值,将该最大值对等交换到首位,再从首位将该最大值对等交换到正确位置.
设置变量len(初始化为A.length),每当有一个大值放在正确位置时,len--;
当len==0时,停止循环,返回结果;
(开始尝试做中等难度的题目,题目不简单,哈哈)

### 代码

```java
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> out = new ArrayList<>();
        boolean active = false;
        int target =  A.length;
        int len = A.length-1;
        int left = 0;
    	int right = 0;
        while(len>0) {
        	int i = 0;
        	while(i<A.length) {
        		if(A[i]==target&&i<len) {
        			target--;
        			active = true;
        			break;
        		}else if(A[i]==target&&i==len){
        			target--;
        			len--;
        			active = false;
        			break;
        		}else {
        			active = false;
        			i++;
        		}
        	}
        	if(active&&len>1) {
            	out.add(i+1);
            	left = 0;
            	right = i;
            	while(left<right) {
            		int temp = A[left];
            		A[left] = A[right];
            		A[right] = temp;
            		left++;
            		right--;
            	}
            	left = 0;
            	right = len;
            	out.add(len+1);
            	while(left <right) {
            		int temp = A[left];
            		A[left] = A[right];
            		A[right] = temp;
            		left++;
            		right--;
            	}
            	len--;
        	}else if(active&&len<=1){
        		left = 0;
            	right = len;
            	out.add(len+1);
            	while(left <right) {
            		int temp = A[left];
            		A[left] = A[right];
            		A[right] = temp;
            		left++;
            		right--;
            	}
            	len--;
        	}
        }
        return out;
    }
}
```