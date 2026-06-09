### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int temp;
        temp = digits[digits.length-1];
        digits[digits.length-1] = temp+1;//将整型数组的最后一个元素加1
        for(int i = digits.length-1;i>0;i--){
/*for循环判断从最后一个元素到下标为1的第二个元素的值是否等于10，若等于10，则前一个元素值加1。*/
            if(digits[i]==10){
                digits[i]=0;
                digits[i-1] = digits[i-1]+1;
            }
        } 
//判断第一个元素是否等于10
        if(digits[0]==10) {//第一个元素值等于10，则创建一个新的整型数组digits1，长度为digits.length+1
        	int[] digits1 = new int[digits.length+1];
        	digits1[0] = 1;
        	digits1[1] = 0;
        	for(int i=1;i<digits.length;i++) {
        		digits1[i+1] = digits[i];
        	}
        	return digits1;//返回digits1
        }
//第一个元素不等于10，直接返回digits
        return digits;
    }
}
```