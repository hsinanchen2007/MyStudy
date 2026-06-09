我想到的解法比较直接，就是将 nums 数组中出现的数字及其频率存入 hashMap 中，之后对 hashMap 进行排序，再依照题目要求将符合要求的答案存入 list 并返回即可。

菜鸡代码如下：（其中 "import java.util.Map.Entry;" 必须添加，否则会报错）
```
import java.util.Map.Entry;
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        Map<Integer,Integer> map = new HashMap<>();
        for(int i = 0;i < nums.length;i++) {
            map.put(nums[i],map.getOrDefault(nums[i],0) + 1);
        }
        List<Map.Entry<Integer,Integer>> res = new ArrayList<>(map.entrySet());
        Collections.sort(res,new Comparator<Map.Entry<Integer,Integer>>() {
			@Override
			public int compare(Entry<Integer, Integer> o1, Entry<Integer, Integer> o2) {
				// TODO Auto-generated method stub
				return o1.getValue() - o2.getValue();
			}
        });
        //System.out.println(res);
        for(int i = map.size() - 1;i >= map.size() - k;i--) {
            list.add(res.get(i).getKey());
        }
        map.clear();
        return list;
    }
}
```
