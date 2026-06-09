
### 代码

```java
public class Solution {
    public static List<List<Integer>> subsetsWithDup(int[] nums) {
    	List<List<Integer>> res = new ArrayList<List<Integer>>();
        //辅助list,用于存放不相同的sub对应的字符串
    	List<String> ans = new ArrayList<String>();
        int len = nums.length;
        int n = 1<<len;
        //正常的求子集,包含重复子集
        for (int i = 0; i < n; i++) {
            List<Integer> sub = new ArrayList<Integer>();
            for (int j = 0; j < len; j++)
                if (((i >> j) & 1) == 1) sub.add(nums[j]);
            String srtList = listToString(sub);

            //判断
            if(!ans.contains(srtList)){
            	ans.add(srtList);
            	res.add(sub);
            } 
        }
        return res;
    }
    
    //将列表转换成字符串
    public static String listToString(List<Integer> l1){
    	Object[] o1 = l1.toArray();
    	Arrays.sort(o1);
		StringBuilder sb1 = new StringBuilder();
		for (int k = 0; k < o1.length; k++) {
			sb1.append(o1[k]);
		}
		return sb1.toString();
    }
}
```