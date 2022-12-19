### 解题思路
把全部的路径加到一个List里, 按content分组, 筛选出长度大于1的组 ,把格式改成要求的样子

### 代码

```java
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
		List<String> list = new LinkedList<>();
		
		for(int i=0;i<paths.length;i++){
			String[] ss = paths[i].split(" ");
			for(int j=1;j<ss.length;j++){
				list.add(ss[0]+" "+ss[j]);
			}
		}
		
		Map<String, List<String>> map=
			list.stream().collect(Collectors.groupingBy(s->s.replaceFirst(".+\\(", "")));
		
		Function<List<String>, List<String>> mapper = 
			alist->alist.stream()
					.map(str->str.replaceAll("\\(.+\\)", "").replace(" ", "/"))
					.collect(Collectors.toList());
		
		List<List<String>> result=
				map.values().stream()
							.filter(alist->alist.size()>1)
							.map(mapper)
							.collect(Collectors.toList());
	
		return result;
	}
}
```