### 解题思路
此处撰写解题思路
看到前K个类型的题目，最先想到的办法就是使用优先队列，所以优先级的判定则为出现的频率
统计出现的频率的最好的办法就是使用HashMap
两者结合，从优先队列中提取出前K个优先级最高的元素对应的值即可
### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> r=new ArrayList<Integer>();        
        if(nums.length==0) {
            return r;
        }

        HashMap<Integer, Integer> map=new HashMap<Integer,Integer>();
        for(int i: nums) {
            map.put(i, map.getOrDefault(i, 0)+1);
        }
		Comparator<EleandFre> comp=new Comparator<EleandFre>() {
			
			@Override
			public int compare(EleandFre o1, EleandFre o2) {
				// TODO Auto-generated method stub
				return -(o1.fre-o2.fre);
			}
		};
        PriorityQueue<EleandFre> q=new PriorityQueue<EleandFre>(comp);
        for(int i: map.keySet()) {
            q.add(new EleandFre(i, map.get(i)));
        }
        for(int i=0; i<k; i++) {
            r.add(q.poll().val);
        }
        return r;
    }
}

class EleandFre {
    int val;
    int fre;
    public EleandFre(int val, int fre) {
        this.val=val;
        this.fre=fre;
    }
}
```