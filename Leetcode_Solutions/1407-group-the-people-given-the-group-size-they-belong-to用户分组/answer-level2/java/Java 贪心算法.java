#### 第一步：观察groupSizes数组

在数组中，我们发现，每个数字出现的次数都大于等于其本身的值

#### 第二部：联想一下

我们可以通过双层遍历找到一组的值

#### 第三步：防止重复

我们要设立一个同等大小的标志位来标记该数字是否已经被取过

#### 代码如下：

``` java
class Solution {
    	public List<List<Integer>> groupThePeople(int[] groupSizes) {	
    		List<List<Integer>> res = new Vector<List<Integer>>();// 这是大组
    		boolean flag[] = new boolean[groupSizes.length];// 设置标记位数组
    		for (int i = 0; i < flag.length; i++) {
			flag[i] = true;
		}
    		for (int i = 0; i < groupSizes.length; i++) {  // 未被取过的数组可以成为新分组的成员
    			if(flag[i]) {  	
    				List<Integer> t = new Vector<Integer>();  // 创建新的小分组
    				t.add(i);       // 添加当前值
        			flag[i] = false;// 将当前的值标记
        			for (int j = i+1; j < flag.length && t.size() < groupSizes[i]; j++) {  // 顺着当前值找同组值
        				if(groupSizes[i] == groupSizes[j]) {  // 找到啦！
        					t.add(j);       // 把它加入组内
						flag[j] = false;// 标记一下
					}
				}
        			res.add(t);  // 把小组加入大组
    			}
		}
    		return res;
	}
}
```

#### 复杂度分析（瞎分析）

时间复杂度：O(n^2)
空间复杂度：O(2*n)