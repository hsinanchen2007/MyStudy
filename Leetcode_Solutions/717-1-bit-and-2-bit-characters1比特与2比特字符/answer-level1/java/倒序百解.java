### 解题思路
简而言之，就是对各种分类。
### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        if(bits[bits.length-1]==1) {   //最后结尾若为1
        	return false;
        }
        if(bits.length==1||bits[bits.length-2]==0) {	//就是一个0或者至少以00结尾
        	return true;
        }
        int count=0;  //结尾0前的连续1个数
        for(int i=bits.length-2;i>=0;i--) {
        	if(bits[i]==1) {
        		count++;
        	}else {
        		break;    
        	}
        }        
		return count%2==0;   //1为偶数则可分解为数个11，成立。否则最后需要补0
    }
}
```