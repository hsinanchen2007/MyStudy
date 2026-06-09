遍历结束后，如果三个数之间存在相等数，则表示第三大的数不存在，时间复杂度O（n）
```
public class Solution {
    public int thirdMax(int[] nums) {
    	int min=Integer.MAX_VALUE;
    	for(int num:nums) {
    		if(num<min) {
    			min=num;
    		}
    	}
    	int first=min;
    	int second=min;
    	int third=min;
    	for(int num:nums) {
    		if(num>first) {
    			third=second;
    			second=first;
    			first=num;
    		}else if (num<first && num > second) {
				third=second;
				second=num;
			}else if(num<second && num>third) {
				third=num;
			}
    	}
        if(first==second || second==third) {
        return first;	
        }
        return third;
        }
}
```
