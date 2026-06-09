建立三张表   
分别为  
      stations  key 站名     value 行程单ID    1对多
       umap key 用户ID    value 行程ID   1对1   用户出站后可以认为行程已经结束 重新分配行程ID
       atime key  行程ID    value 行程信息

**入站    新增行程到站点,更新用户关系对应表 插入行程记录**

**出站    新增行程到站点  因为肯定已经入站  所以可以直接从用户表读取行程ID， 更新行程出站记录**

**统计时间   直接统计两个站点下的 同一行程记录   行程记录对应出站入站数据**




```
class UndergroundSystem {
        Map<String, List<Integer>> stations =new HashMap<>(); //站台 行程ID对应表
        Map<Integer,Integer> umap =new HashMap<>();  //用户ID 行程ID 对应表
        Map<Integer,int[]> atime = new HashMap<>(); //行程ID,行程出入站对应表
 
        Set<Integer> isCheckIn =new HashSet<>();  //是否入站  排查脏数据
        public volatile int sid = 100;  //自增行程ID

        public UndergroundSystem() {

        }

      public synchronized void checkIn(int id, String stationName, int t) {
            if(isCheckIn.contains(id))
                return ;
            isCheckIn.add(id);
            List<Integer> list;
            if(!stations.containsKey(stationName)){
                list = new ArrayList<>();
                stations.put(stationName,list);
            }else
                list = stations.get(stationName);
            int keyId= sid++;
            list.add(keyId);
            umap.put(id,keyId);
            atime.put(keyId,new int[]{t,0});
        }

        public  void checkOut(int id, String stationName, int t) {
            if(!isCheckIn.contains(id))
                return;
            List<Integer> list;
            if(!stations.containsKey(stationName)){
                list = new ArrayList<>();
                stations.put(stationName,list);
            }else
                list = stations.get(stationName);
            isCheckIn.remove(id);
            int key = umap.getOrDefault(id,0);
            if(key==0)
                return;
            if(!list.contains(key))
                 list.add(key);
            atime.get(key)[1]= t;

        }

        public  double getAverageTime(String startStation, String endStation) {
            List<Integer> in = stations.get(startStation);
            List<Integer> out = stations.get(endStation);
            if(in==null||out==null)
                return 0d;
            int count =0;
            double total = 0;
            for(int i=0;i<in.size();i++){
                for(int j=0;j<out.size();j++){
                    if(in.get(i).equals(out.get(j))){
                       int[] arr =  atime.get(in.get(i));
                       if(arr[1]>arr[0]){
                           total+= arr[1]-arr[0];
                           count++;
                       }
                    }
                }
            }
            if(count>0){
                return total/count;
            }
            return 0d;
        }


}
```



