### 解题思路
  早上竞赛时的思路是先排序，然后根据排序之后的数组进行划分，用户所在分组的大小即为分组List的长度，但是我没想到排序之后的数组groupSizes的下标已经乱了，所得答案不再符合题意。提交错误之后就吃早餐去了。
  后来我想到一种硬解的方式，还是沿用上午写的逻辑，但是我这次把数据的值和下标都用Map存起来，根据值排序之后下标不会丢失，只是空间消耗好像有点大，所以说这是硬解。使用Java解题的代码如下。

### 代码

```java
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> resultList = new LinkedList<List<Integer>>();
        List<Integer> eachGroup = null;
        // 对数组进行排序，然后再进行后续的操作！20191208 10:45
        // 进行排序就是错的！20191208 11:23        
        // 使用Map存储数组，进行排序
        List<Map<Integer, Integer>> itemList = new LinkedList<Map<Integer,Integer>>();
        Map<Integer, Integer> item = null;
        for (int i = 0; i < groupSizes.length; i++) {
			item = new HashMap<Integer, Integer>();
//			item.put(i, groupSizes[i]);
			item.put(-1, i);
			item.put(-2, groupSizes[i]);
			itemList.add(item);
		}
        boolean flag = true;
        // 冒泡排序，存储下标和值。 20191208 15:01
        for (int i = 0; i < itemList.size(); i++) {
        	for (int j = 0; j < itemList.size() - i -1; j++) {
				if (itemList.get(j).get(-2) > itemList.get(j+1).get(-2)) {
					itemList.set(j+1, itemList.set(j, itemList.get(j+1)));
					
					flag = false;
				}
			}
        	if (flag) {
				break;
			}
		}
        int j = 0;
        for (int i = 0; i < groupSizes.length;) {
			// 有序数组，升序排列
        	eachGroup = new LinkedList<Integer>();
        	// 将符合条件的数据放入用户组中
        	// 错误！放的是下标！！！ 20191208 11:20
        	for (j = 0; j < itemList.get(i).get(-2); j++) {
        		eachGroup.add(itemList.get(i+j).get(-1));
			}
        	i+=j;
        	// 将用户组放入解决方案中
        	resultList.add(eachGroup);
        	if (i+j>groupSizes.length) {
        		break;
        	}
		}
		return resultList;
    }
}
```