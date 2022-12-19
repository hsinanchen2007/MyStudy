### 解题思路
（如果数组中有两个6，第一个三元组用第一个6，第二个三元组用第二个6，哎，不是钻牛角尖，这不算重复吧..........真是啊）
1、对于外层循环，每次循环完，就要把当前的值去掉，因为这个值对应的组合都查找完毕，后续再碰到重复着直接跳过。我用的方法是把当前值和对应的索引更新到map中。

2、对与内层循环，除了和外层同样的判断，另重新定义一个map,存放处理过的值，如果碰到满足要求的值，两个值都要存放到map中。

不知道为什么我用了两个map,内存消耗竟然还是击败了百分之九十多用户。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list= new ArrayList<List<Integer>>();
		Map<Integer, Integer> map=new HashMap<Integer, Integer>();
		for(int i=0;i<nums.length;i++) {
			map.put(nums[i], i);
		}
		for(int i=0;i<nums.length;i++) {
			int a=nums[i];
            if(i>map.get(a)){
                continue;
            }
            Map<Integer, Integer> map2=new HashMap<Integer, Integer>();
			for(int j=i+1;j<nums.length;j++) {                
				int b=nums[j];
                if(null!=map2.get(b)||map.get(b)<j){
                     continue;
                 }
				Integer c = map.get(0-a-b);
				if(c!=null&&c>j) {
					List<Integer> tl=new ArrayList<>();
					tl.add(a);
					tl.add(b);
					tl.add(0-a-b);
					list.add(tl);
                    map2.put(0-a-b,c);
                    //list2.add(""+a+b);
				}
               map2.put(b,j);
			}
			map.put(a, i);
		}
		return list;
    }
}
```