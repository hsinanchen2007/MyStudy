使用map来统计频率，在使用最大堆来得到频率的排序，从而每次选择最大会第二大的频率来填充数组。
```livescript
public int[] rearrangeBarcodes(int[] barcodes) {

        PriorityQueue<Map.Entry<Integer,Integer>> queue = new PriorityQueue<>(((o1, o2) -> o2.getValue()-o1.getValue()));
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int code:barcodes) map.put(code,map.getOrDefault(code,0)+1);
        for(Map.Entry entry:map.entrySet()){
            queue.add(entry);
        }
        int[] res = new int[barcodes.length];
        for(int i=0;i<barcodes.length;i++){
            Map.Entry entry = queue.poll();
            if(i==0){
                res[i] = (int)entry.getKey();
                entry.setValue((int)entry.getValue()-1);
                queue.add(entry);
                continue;
            }
            if(res[i-1]!=(int)entry.getKey()){
                res[i] = (int)entry.getKey();
                 entry.setValue((int)entry.getValue()-1);
                queue.add(entry);
            }else {
                Map.Entry entry2 = queue.poll();
                res[i] =(int)entry2.getKey();
                entry2.setValue((int)entry2.getValue()-1);
                queue.add(entry);
                queue.add(entry2);
            }

        }
        return res;
    }
        
```