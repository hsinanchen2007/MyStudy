题解里面双向链表+贪心的思路  java实现

nlgn来自于构建优先队列的时间复杂度


```
class Solution {
    public int maxSizeSlices(int[] slices) {
        ArrayList<Map<String, Object>> list = new ArrayList();
        //构建一个双向链表
        createLink(slices, list);
        //大根堆
        PriorityQueue<Map<String, Object>> queue = new PriorityQueue<Map<String, Object>>(new Comparator<Map<String, Object>>() {
            public int compare(Map<String, Object> t1, Map<String, Object> t2) {
                int v1 = Integer.valueOf(t1.get("val")+"");
                int v2 = Integer.valueOf(t2.get("val")+"");
                return  v2-v1;
            }
        });
        for (int i = 0; i < list.size();i ++) {
            queue.add(list.get(i));
        }
        int res = 0;
        int count = 0;
        
        //每次取最大的值，包括的操作有
        //1：取出最大的值currentVal
        //2：计算leftVal+rightVal-val,通过这个值构造一个新的节点加入到queue
        //3：将这个值的左右孩子都移除队列
        //4：重新设置链表左右关系
        while (count < slices.length/3){
            Map<String, Object> current = queue.poll();
            Map<String, Object> left = (Map<String, Object>) current.get("left");
            Map<String, Object> right = (Map<String, Object>) current.get("right");

            int currentVal = Integer.valueOf(current.get("val")+"");
            int leftVal = Integer.valueOf(left.get("val")+"");
            int rightVal = Integer.valueOf(right.get("val")+"");
            res = currentVal + res;

            //重新设置链表左右的关联关系
            Map<String, Object> left_l = (Map<String, Object>) left.get("left");
            Map<String, Object> right_r = (Map<String, Object>) right.get("right");
            Map<String, Object> newNode = new HashMap<String, Object>();
            newNode.put("val", leftVal + rightVal - currentVal);
            newNode.put("left", left_l);
            newNode.put("right", right_r);
            left_l.put("right", newNode);
            right_r.put("left", newNode);
            
            //移除左右孩子
            queue.remove(left);
            queue.remove(right);
            //新产生的节点加入队列
            queue.add(newNode);
            count++;
        }
        return res;
    }

    //根据数组构造一个双向列表 map->key (val, left, right)
    public void createLink(int[] slices, ArrayList<Map<String, Object>> array){
        for (int i = 0;i < slices.length;i ++){
            Map<String, Object> map = new HashMap<>();
            map.put("val", slices[i]);
            array.add(map);
        }

        for (int i = 0;i < array.size();i ++){
            int left = i - 1;
            int right = i + 1;
            if (i == 0){
                left = slices.length - 1;
            }
            if (i == slices.length - 1){
                right = 0;
            }
            Map<String, Object> currentMap = array.get(i);
            Map<String, Object> leftMap = array.get(left);
            Map<String, Object> rightMap = array.get(right);
            currentMap.put("left", leftMap);
            currentMap.put("right", rightMap);
        }
    }

}
```

