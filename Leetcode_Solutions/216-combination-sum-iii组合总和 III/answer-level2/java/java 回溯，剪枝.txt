### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	static List<List<Integer>> res = new ArrayList<>();
    public static List<List<Integer>> combinationSum3(int k, int n) {
        res.clear();
    	if(k<=0||n<=0||k>n)  return res;
    	List<Integer> list = new ArrayList<>();
    	process(1,n, k, list);
		return res;    	
    }
    private static void process(int start,int rest,int k, List<Integer> list){
    	if(rest<0)   return;
        if (k == 0) {
            if (rest == 0) {
               res.add(new ArrayList<>(list));
               return;
            }
            return;
        }
    	for (int i = start; i <=9; i++) {
			list.add(i);
			process(i+1,rest-i, k-1,  list);
			list.remove(list.size()-1);		
		}
    }
}
```