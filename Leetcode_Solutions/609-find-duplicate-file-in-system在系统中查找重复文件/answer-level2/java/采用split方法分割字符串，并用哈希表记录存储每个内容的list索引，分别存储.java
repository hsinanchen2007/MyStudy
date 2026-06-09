首先对于这一题可以分析一下样例：
String[] paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
文件路径和文件名之间由空格隔开，从而用split函数可以**分割出路径名 和 文件名**。
对于每个 paths[i] 都有一个分割出的String数组 check，**check[0]就是路径名**（由于一个路径中存在多个文件，还是遍历后面的文件名比较合适）。

接下来有这么几种情况：
1. 前面没有出现过的内容，map<String,Integer>中压入**check[i].substring(left,right)** 和 **index**。
`index 即为 ans.get(index)，即该文件所应该加入的列表`
重新创建一个 list，并向其中添加文件的绝对路径：check[0] + "/" + check[i].substring(0,left - 1)，将 list 加入 ans 中；
2. 前面出现过的内容，找到其对应的index，再向 ans.get(index) 中加入即可

代码如下：
```
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        HashMap<String,Integer> map = new HashMap<>();
		List<List<String>> res = new ArrayList<>(); /* 存放处理结果 */
		int index = 0; /* 记录第index个非重复内容，index从0开始计算，和索引一致 */
		for(String tar : paths) { 
			String[] check = tar.split(" "); /* 分割 paths[i] */
			for(int i = 1;i < check.length;i++) {
				int left = 0,right = 0; /* 记录内容的首索引和尾索引 */
				for(int j = 0;j < check[i].length();j++) {
					if(check[i].charAt(j) == '(') left = j + 1;
					else if(check[i].charAt(j) == ')') right = j;
				}
				String n = check[i].substring(left, right); /* 此为文件的内容 */

				if(!map.containsKey(n)) { /* 第一种情况，前面未出现过相同的内容 */
					map.put(n, index);index++;
					List<String> list = new ArrayList<>();
					list.add(check[0] + "/" + check[i].substring(0, left - 1));res.add(list);
				}
				else { /* 第二种情况，前面出现过相同内容 */
					res.get(map.get(n)).add(check[0] + "/" + check[i].substring(0, left - 1));
				}
			}
		}
        List<List<String>> ans = new ArrayList<>(); /* 存放最后答案 */ 

        for(int i = 0;i < res.size();i++) { /* 对 res 进行处理，因为内容独一无二的文件不算重复，但是经过处理会存在 res 中 */ 
            if(res.get(i).size() > 1) ans.add(res.get(i)); 
        }
        return ans;
    }
}
```
（为啥把提交的代码复制过来之后排版会变成这样呢？QWQ）
（方法可能不够高效，请各位大佬多多包含，顺便可以提提建议）