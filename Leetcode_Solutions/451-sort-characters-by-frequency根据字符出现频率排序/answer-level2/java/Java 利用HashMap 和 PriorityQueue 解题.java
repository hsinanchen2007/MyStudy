1. 先统计字符串s中各个字符的频率
2. 自定义Item存储字符和对应的频率，然后根据字符频率创建优先队列
3. 挨个从队列中取出元素Item，根据字符和频率拼接出结果
```
public String frequencySort(String s) {
        class Item{

            public Item(Character character, Integer count) {
                this.character = character;
                this.count = count;
            }

            private Character character;
            private int count;
        }
        Map<Character,Integer> map = new HashMap<>();
        PriorityQueue<Item> priorityQueue = new PriorityQueue<>((item1,item2)->item2.count-item1.count);

        for (int i=0;i<s.length();i++){
            char c = s.charAt(i);
            map.put(c,map.get(c)==null?1:map.get(c)+1);
        }

        map.forEach((k,v)->{
            final Item item = new Item(k, v);
            priorityQueue.offer(item);
        });
        StringBuilder stringBuilder = new StringBuilder();
        while(!priorityQueue.isEmpty()){
            final Item item = priorityQueue.poll();
            for (int i = 0; i < item.count; i++) {
                stringBuilder.append(item.character);
            }
        }
        return stringBuilder.toString();

    }
```
