**解题思路:**
根据题意和样例，votes 数组中所有的字符串中相同种类的字符且每种字符只有一个。
从而可以用 List<int[]> res 存放该 **队伍名称** 和 **第1~n的排名的获得次数**。
`数组长度为 1（队伍名） + 队伍总数（有多少种排名投票）`
设数组名为 arr，其中 (char)(arr[0] + 'A') 即为相应的队伍名，后面则是 “排名为 1”、“排名为 2”、………“排名为 n”的出现次数。
遍历 votes[] 数组，根据遍历到的字符确定是 list 中的哪个数组，在根据其在 votes[i] 的索引位置对应进行 arr[i + 1] += 1 操作。

经过处理后，对 res 进行排序，在从头至尾将数组的第一个值连接成字符串即可。 

**代码如下：**
```
class Solution {
    public String rankTeams(String[] votes) {
        List<int[]> res = new ArrayList<>(); /* 存放排序结果 */
	int n = votes[0].length(); /* votes[0] 中即存在着所有的队伍名称 */
	for(int i = 0;i < n;i++) {
            int[] arr = new int[n + 1]; /* 创建对应的数组 */
            arr[0] = votes[0].charAt(i) - 'A'; /* 将队伍名称转化为数字赋值给 arr[0] */
	    res.add(arr);
	}
	for(String vote : votes) { /* 开始处理 votes[] 数组 */
	    for(int i = 0;i < n;i++) { /* 处理 vote 字符串 */
		for(int j = 0;j < res.size();j++) {
		    if(res.get(j)[0] == vote.charAt(i) - 'A') { /* 找到队伍对应的数组 */
                        res.get(j)[i + 1] += 1; /* 对应的排名数量 + 1 */
		    }
		}
	    }
	}
	Collections.sort(res, new Comparator<int[]>() { /* 排序 */
	    @Override
	    public int compare(int[] o1,int[] o2) {
		// TODO Auto-generated method stub
		for(int i = 1;i < o1.length;i++) {
		    if(o1[i] != o2[i]) return o2[i] - o1[i]; /* 存在不一样的排序数量按照降序排 */
		    else continue;
		}
		return o1[0] - o2[0]; /* 所有排名的数量都一样时，按照字母顺序升序排 */
	    }
	});
	String ans = "";
	for(int i = 0;i < res.size();i++) {
	    ans = ans + String.valueOf((char)(res.get(i)[0] + 'A')); /* 拼接答案字符串 */
	}
	return ans;
    }
}
```

（PS：本题也可以用 List<List<Integer>> 来实现，但是数组操作比 List<Integer> 快点，故采用数组）