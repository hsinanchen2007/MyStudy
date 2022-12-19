### 解题思路
核心思想就是找到出现次数最多的字符（记为字符x），把那个按间隔排开。其他字符往间隔插入。分为几种情况。
1 有次数和x一样的字符，这些字符会加长最终长度。因为这些字符的最后一个会排在x的后面
2 空格不够的，会加大最终长度。因为要在间隔插入空格。
3 其余情况不会增加最终长度

如: ['A','A','A','A','B','B','B','B','C','C','D','D','E'] 2
先把A排开， 变成 A - - A - - A - - A
插入B，变成 A B - A B - A B - A B (由于B和A一样是三次，故最后长度+1)
插入C，变成 A B C A B C A B - A B (此时还有空格，长度不变)
插入第一个D, 变成 A B C A B C A B D A B (此时还有空格，长度不变)
插入第二个D, 此时无空格，D随意插入(只要不在上一个D旁边)，长度必然+1，如：A B C D A B C A B D A B E
插入E, 此时无空格，E随意插入位置，长度必然+1，如：A B C D E A B C A B D A B E

### 代码

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        //统计出现次数，排序
		int[] counts = new int[26];
		for(char ch: tasks){
			counts[ch-'A']++;
		}
		Arrays.sort(counts);
		
		int maxCycle = counts[25];                    //找到出现次数最多的是多少次
		int emptyPosition = (maxCycle-1) * (n + 1);   //有多少个空位
		int result = emptyPosition;                   //最后结果必不少于空位数
		int element = 0;
		for(int count : counts){
			if(count == maxCycle){
				result++;
				element += count-1;
			}else{
				element += count;
			}
		}
		if(element <= emptyPosition){
			return result;
		}else{
			return result + (element - emptyPosition);
		}
    }
}
```