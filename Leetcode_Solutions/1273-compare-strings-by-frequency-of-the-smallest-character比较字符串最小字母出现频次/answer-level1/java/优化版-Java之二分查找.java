import java.util.Arrays;
class Solution {
	
	public int f(String s) {
		if(s==null || s.length()==0)
			return 0;
		int[] char_num = new int[26];
		char[] chars = s.toCharArray();
		//没有对字符数组进行排序后进行统计，笔者认为遍历整个数组更快，消耗空间也是常数空间
		for(char ch : chars) 
			char_num[ch-'a']++;
		for(int num : char_num)
			if(num > 0)
				return num;
		return 0;
	}
	
	public int binarySearch(int queryNum, int[] target) {
		//二分查找的稍微更改，寻找第一个比queryNum大的值，并统计其后还有多少值。
		int left = 0, right = target.length-1;
		while(left < right) {
			int mid = (left+right)/2;
			if(target[mid] > queryNum)
				right = mid;
			else
				left = mid+1;
		}
		if(target[left] <= queryNum)//注意这里，等于也是不符合条件的。
			return 0;
		else
			return target.length-left;
	}
	
	public int[] numSmallerByFrequency(String[] queries, String[] words){
		int[] res = new int[queries.length];
		int[] target = new int[words.length];
		for(int i=0; i<words.length; i++)
			target[i] = f(words[i]);
		Arrays.sort(target);//进行排序，排序的数组通常使用二分查找
		
		for(int i=0; i<queries.length; i++) {
			int queryNum = f(queries[i]);
			res[i] = binarySearch(queryNum, target);//二分查找更快，在可以提高效率的地方，努力改进。
		}
		return res;
    }
}