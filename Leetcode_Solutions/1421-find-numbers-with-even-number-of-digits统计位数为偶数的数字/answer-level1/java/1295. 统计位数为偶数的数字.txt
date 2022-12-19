### 解题思路
根据题目给出的边界范围，采用折半比较的思想，先除以1000，再根据所得结果除以10进行分类讨论

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int num = 0;
        int number1, number2;
        for(int i = 0; i < nums.length; i++){
        	number1 = nums[i] / 1000;
        	if(number1 > 0){
        		number2 = number1 / 10;
        		if(number2 >= 1 && number2 <= 9){
            		continue;
            	}else{
            		num++;
            	}
        	}else{
        		number2 = nums[i] / 10;
        		if(number2 >= 10 || number2 <= 0){
        			continue;
        		}else{
        			num++;
        		}
        	}
        	
        }
        return num;
    }
}
```