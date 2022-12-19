### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck){
		/*
		 * 排序，记录每个数字出现的次数，如果所有数字出现的次数存在一个大于1的公因数，那么返回true；否则返回false
		 */
		if(deck.length < 2){
			return false;
		}
		Arrays.sort(deck);
		List<Integer> counts = new ArrayList<>();
		int last = deck[0];
		int count = 1;
		for(int i=1;i<deck.length;i++){
			if(deck[i] != last){
				if(count < 2){
					return false;
				}
				counts.add(count);
				count = 1;
				last = deck[i];
			}else{
				if(i == deck.length-1){
					count++;
					counts.add(count);
				}else{
					count++;
				}
			}
		}
		if(findFactor(counts) > 1){
			return true;
		}else{
			return false;
		}
	}
	
	public int findFactor(List<Integer> counts){
		int min = findMin(counts);// 记录最小的count
		for(int i=2;i<=min;i++){
			for(int j=0;j<counts.size();j++){
				int curr = counts.get(j);
				if(curr % i != 0){
					break;
				}else{
					// 若counts中所有元素都可以整除i，则返回i
					if(j == counts.size()-1){
						return i;
					}
				}
			}
		}
		return 1;
	}
	
	public int findMin(List<Integer> counts){
		int min = counts.get(0);
		if(counts.size() == 1){
			return min;
		}
		for(int i=1;i<counts.size();i++){
			int curr = counts.get(i);
			if(curr < min){
				min = curr;
			}
		}
		return min;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/e7d98a84feca0065612648e929ab1db903f9959e9ace6847bf2176cffc2aec65-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/39b5259bae545a949437fa5cc49bf803436ce9fd74e628f3b1421473b73ab5dc-wechat.png)

