排序视频用了List来自定义排序，时间和空间超100%，不过目前提交700次加上数据量本身较小，排名可能参考意义不大。

思路：
首先根据初始id和level确定friends里的好友，注意题目要求为最短距离为k的好友，不是从0到k层的所有好友。
因为涉及到层，所以采用BFS广度优先搜索，自然想到使用队列来遍历朋友圈。
这里的一个难点就是限制了k层，对于一般的树来说只要遍历到队列queue为空即可，但这里：
1. “如果 friends[i] 包含j ，那么 friends[j] 包含 i”，为防止人脉绕一圈又回去而返回错误的id（关系比k近了），将先前遍历过的朋友id存入一个Set集合，每次遍历前先判断是否已经找过；
2. “最短距离为k的好友”，遍历的时候需要记录当前是多少层，对于前k-1层的id则不需要返回。

之后，得到第k层的好友id，就可以统计他们所看视频的数目了。对于某个vedio看了多少次，用Map来存储最合适不过了。一方面，<String, Integer>键值对可以储存vedio和它对应的频率；一方面，统计的时候查找某个vedio时间复杂度只有1。

对于统计出来的vedio，可以把它转化成List, 然后利用Collections类里的sort来排序。
这里重写了sort方法来达到题目要求，具体见代码：


```
class Solution {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        Set<Integer> allFriends = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(id);
        allFriends.add(id);
        int l = 0;  //记录当前层数
        while(!queue.isEmpty() && l<level){
            int size = queue.size();    //size表示当前层的人数
            for(int i=0; i<size; i++){  //遍历这一层
                int person = queue.poll();
                int[] fs = friends[person];
                for(int f: fs){
                    if(!allFriends.contains(f)){
                        queue.add(f);
                        allFriends.add(f);
                    }
                }
            }
            l++;    //下一层
        }
        
        Map<String,Integer> map = new HashMap<>();
        while(!queue.isEmpty()){
            int f = queue.poll();
            List<String> wv = watchedVideos.get(f);
            for(String v: wv){               
                int count = map.getOrDefault(v, 0);
                map.put(v, ++count);
            }      
        }
        
        List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String, Integer>>(map.entrySet()); //转换为list
        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
           @Override
            public int compare(Map.Entry<String, Integer> t1, Map.Entry<String, Integer> t2) {
                if (t1.getValue().equals(t2.getValue())) {  //如果两个vedio的频率相同，按名字排序
                    return t1.getKey().compareTo(t2.getKey());
                } else {    //video按频率排序，从小到大
                    return t1.getValue().compareTo(t2.getValue());
                }
           }
       });

        List<String> ans = new ArrayList<>();
        for(Map.Entry<String,Integer> m: list){
            ans.add(m.getKey());
        }
        return ans;        
    }
}
```
