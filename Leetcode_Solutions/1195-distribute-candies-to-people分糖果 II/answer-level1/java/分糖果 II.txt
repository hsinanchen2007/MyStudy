### 解题思路
1. 定义 $nums$ 数组存放每个小朋友获得的糖果数量
2. 定义变量 $i$ 递增并对人数取模赋值给 $k$ 表示当前第几个小朋友获得糖果
3. 定义变量 $n$ 表示获得的糖果数量
4. 如果 $n$ 大于糖果数量则把所有糖果给下标为 $k$ 的小朋友，否则糖果总数 $-n$


### 代码

```java [-Java]
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
int[] nums = new int[num_people];
    	int i = 0;
    	while(candies!=0){
    		int k = i%num_people;
    		int n = i+1;
    		if(n<=candies){
    			nums[k] = nums[k]+n;
    			candies = candies-n;
    		}else{
    			nums[k] = nums[k]+candies;
    			break;
    		}
    		i++;
    	}
    	System.out.println(Arrays.toString(nums));
    	return nums;
    }
}
```