### 解题思路
Set:注重独一无二的性质,该体系集合可以知道某物是否已近存在于集合中,不会存储重复的元素
set hashset:https://blog.csdn.net/qq_33642117/article/details/52040345
| Itreable      接口 实现该接口可以使用增强for循环
				---| Collection		描述所有集合共性的接口
					---| List接口	    有序，可以重复，有角标的集合
                            ---| ArrayList   
                            ---|  LinkedList
					---| Set接口	    无序，不可以重复的集合
                            ---| HashSet  线程不安全，存取速度快。底层是以hash表实现的。
                            ---| TreeSet  红-黑树的数据结构，默认对元素进行自然排序（String）。如果在比较的时候两个对象返回值为0，那么元素重复。
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
    	Set<Integer> hashSet = new HashSet<Integer>();
    	int index = -1;
    	for (int num : nums) {
			if (!hashSet.add(num)) {
				index = num;
				break;
			}
		}
    	return index;

    }
}
```