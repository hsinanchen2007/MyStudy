### 解题思路
反正就这么多种情况嘛, 数一下$5和$10的张数, 对面掏出$10的时候需要有$5;对面掏出$20的时候需要有
3张$5或(1张$10+1张$5)
### 代码

```java
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int $5=0,$10=0;
        for(int i=0;i<bills.length;i++){
        	switch(bills[i]){
        	case 5:
        		$5 ++;
        		break;
        	case 10:
        		if($5>=1){ 
        			$5 --;
        			$10 ++;
        		}
        		else 
					return false;			
        		break;
        	case 20:
        		if($10>=1&&$5>=1){
        			$10 --;
        			$5 --;
        		}
        		else if($5>=3){
        			$5 -= 3;
        		}
        		else 
        			return false;
        		break;
        	}
        }
        return true;
    }
}
```