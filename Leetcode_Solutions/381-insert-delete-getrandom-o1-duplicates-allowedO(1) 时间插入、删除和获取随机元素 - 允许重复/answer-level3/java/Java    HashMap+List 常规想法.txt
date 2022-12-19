# HashMap+List 常规想法

## 分析 

### 数据结构选择
- 想要实现`O(1)`的`random()` 需使用list 集合或数组
- 想要实现`O(1)`的`insert()` 数组做不到
- 想要通过`O(1)`的`remove()` 需使用HashMap存储索引
- 故采用 HashMap+List

### 难点
1. HashMap不能存储重复元素
解决: map 设计为`<String,Integer>` 
```java
//val值第一个元素
map.put(val+"",count);//count为list中val值个个数
//val值剩下元素
map.put(val+"_"+num,index)//num为当前是第几个val元素,index是当前val元素索引
```
2. List移除元素后索引值改变
```java
//在要移除元素前插入Integer.MAX_VALUE,random取得时候取到非Integer.MAX_VALUE再返回
list.add(lastIndex, Integer.MAX_VALUE);
//移除要移除的元素
list.remove(lastIndex + 1);

//这个方法缺点明显 有待改进
```


## java代码

```java
class RandomizedCollection {
    
	Map<String, Integer> map;
	List<Integer> list;

	/** Initialize your data structure here. */
	public RandomizedCollection() {
		map = new HashMap<>();
		list = new ArrayList<>();
	}

	/**
	 * Inserts a value to the collection. Returns true if the collection did not
	 * already contain the specified element.
	 */
	public boolean insert(int val) {
		// 生成对应key值
		if (!map.containsKey(val + "")) {
			map.put(val + "", 0);
		}
		int valCount = map.get(val + "");
		// 加入list集合
		list.add(val);
		// 将已有数量+1
		map.put(val + "_" + (valCount + 1), list.size() - 1);
		// 再put一个数进去
		map.put(val + "", valCount + 1);
		return true;
	}

	/**
	 * Removes a value from the collection. Returns true if the collection
	 * contained the specified element.
	 */
	public boolean remove(int val) {
		if (map.containsKey(val + "")) {
			int valCount = map.get(val + "");
			String lastKey = val + "_" + valCount;
			// int lastIndex = map.get(lastKey);
			// 移除最后一个元素
			int lastIndex = map.remove(lastKey);
			// 替换为最大值
			list.add(lastIndex, Integer.MAX_VALUE);
			list.remove(lastIndex + 1);
			// 更新第一个元素
			if (valCount == 1) {
				// 只有一个元素
				map.remove(val + "");
			} else {
				// 有多个元素
				map.put(val + "", valCount - 1);
			}
			return true;
		}
		return false;
	}

	/** Get a random element from the collection. */
	public int getRandom() {
		Random random = new Random();
		int randomInt = Integer.MAX_VALUE;
		while (randomInt == Integer.MAX_VALUE) {
			randomInt = list.get(random.nextInt(list.size()));
		}
		return randomInt;
	}
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection(); boolean param_1 =
 * obj.insert(val); boolean param_2 = obj.remove(val); int param_3 =
 * obj.getRandom();
 */

```