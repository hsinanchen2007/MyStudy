### 解题思路
把整数X从个位数开始，依次取出十位、百位...数字用数组按顺序保存，然后比较数组对应的前后两个数是否相等。

### 代``码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int[] arr = new int [32];
        
    	if(x > 0){       	 
             int i = 0;
            while(x != 0){
                arr[i] = x % 10;              
                x /= 10;
                //System.out.println(arr[i]);
                i++;                
            }           
            for(int j = 0; j < i-1; j++){
            	//System.out.println(arr[j]);
                if(arr[j] != arr[i-j-1]){
                	return false;
                }              	               
            }
            return true;
        }else if(x == 0){
        	return true;
        }else{
        	return false;
        }
    }
}
```