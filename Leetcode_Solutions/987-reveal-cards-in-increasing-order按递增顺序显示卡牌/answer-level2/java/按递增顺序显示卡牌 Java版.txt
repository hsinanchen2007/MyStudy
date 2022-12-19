```Java []
class DeckRevealedIncreasing{
	/**
	 * 1.倒叙:观察示例可得:
	 *          结果->开始：将下一数组的末尾元素移至开头，再在开头位置插入当前值；
	 *          开始->结果：在结尾部分插入当前值，将上一数组的开头元素移至末尾。
	 * 
	 * 执行用时 :8 ms, 在所有 Java 提交中击败了57.79%的用户
	 * 内存消耗 :38.3 MB, 在所有 Java 提交中击败了70.43%的用户
	 */
	public int[] deckRevealedIncreasing(int[] deck) {
		if(deck.length < 1 || deck ==null) return deck;
		Arrays.sort(deck);	//递增排序
		Queue<Integer> queue = new LinkedList<>();
		for(int i = deck.length - 1; i >= 0; i--) {
			queue.add(deck[i]);  //选取当前数组最大值添加到queue中
			if( i == 0) break;
			queue.add(queue.poll()); //将队头元素插入到队尾
		}
		
		for(int i = deck.length - 1; i >= 0; i--) {
			deck[i] = queue.poll();	 //倒序存储到deck中
		}
		return deck;
	}
}

```
