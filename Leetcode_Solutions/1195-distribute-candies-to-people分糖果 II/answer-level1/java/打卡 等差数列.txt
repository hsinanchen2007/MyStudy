### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
    	int shouXiang = dengChaSum(1, num_people, num_people);
    	int hangCha = num_people * num_people;
    	int hangSum = shouXiang;
    	int hangNum = 1;
    	int[] res = new int[num_people];
    	if(candies <= shouXiang) { //只有一行
    		for(int i = 1;i<=num_people;i++) {
    			if(candies > i) {
    				res[i-1] = i;
    				candies-=i;
    			}else {
    				res[i-1] += candies;
    				break;
    			}
    		}
    		return res;	
    	}
    	while(candies > hangSum) { //比现在行数要多一行（不一定完整）
    		hangSum = dengChaSum(shouXiang, shouXiang + hangNum*hangCha, hangNum+1);
    		hangNum++;
    	}
    	//System.out.println("行数是："+hangNum);
    	int realHangNum = hangNum-1;
    	for(int i = 1;i<=num_people;i++) {
    		res[i-1] += dengChaSum(i, i+num_people*(realHangNum-1), realHangNum);
    		//System.out.println(Arrays.toString(res));
    		candies -= res[i-1];
    	}
    	int lastHangStart = 1 + num_people*realHangNum;
    	for(int i = 1;i<=num_people;i++,lastHangStart++) {
    		if(candies > lastHangStart) {
    			res[i-1] += lastHangStart;
    			candies -= lastHangStart;
    		}else {
    			res[i-1] += candies;
    			break;
    		}
    	}
    	return res;
    }
    
    public int dengChaSum(int start,int end,int items) {
    	return (start + end)*items/2;
    }
}
```