![1585647608531.jpg](https://pic.leetcode-cn.com/37ce273aafa920dfa7117599ba61dd377a0de4906abb0a67c63f70836915961b-1585647608531.jpg)

其实题目的意思很明确，在0-(n-1)这n个数里每次去掉第m个数，因此想到可变长数组，使用list来解决。去掉第m个数就是在当前数的位置向右移动m-1位，如果移动后超出数组长度，则移动到末端之后再从头开始，要注意数组大小每次移除之后会变短。代码如下：
class Solution {
    public int lastRemaining(int n, int m) {
		List<Integer> myList = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			myList.add(i);
		}
		int i=0;
		int index = m-1;
		while (i<n-1) {
			int size = myList.size();
			while (index>=size) {
				index = index-size;
			}
			myList.remove(index);
			index = index+m-1;
			i++;
		}
		return myList.get(0);
	
    }
}
第二次写题解



