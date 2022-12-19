利用所给的公交车和公交车站信息构造一个map存储，key为车站，value是经停公交车list。利用map结构和routes二维数字构建广度优先搜索树，之后按照广度优先搜索算法BFS进行操作，到达每个公交车站所乘坐的公交车使用list存储，最后统计换乘公交车数量。
```
class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (routes.length > 500 || routes.length < 1){
            return -2;
        }
        int maxWidth = 0;
        for (int i =0; i < routes.length; ++i) {
            if (routes[i].length > maxWidth){
                maxWidth = routes[i].length;
            }
        }
        if (maxWidth * routes.length >= 1000000){
            return -4;
        }
        if(S == T){
            return 0;
        }
        //step1. construct one map, key -- stop, value --- bus
        Map<Integer, List<Integer>> stop2bus = constructStop3Bus(routes);
        //BFS
        StopNode destination = BFS(stop2bus, routes, S, T);
        if (destination == null) {
            return -1;
        }
        return destination.getBuses().size();
    }

    private StopNode BFS(Map<Integer, List<Integer>> stop2bus, int[][] routes, int S, int T){
        Queue<StopNode> stops = new LinkedList<StopNode>();
        StopNode s = new StopNode();
        s.setCode(S);
        s.setBuses(new LinkedList<Integer>());
        stops.offer(s);
        while(stops.size() > 0){
            StopNode stop = stops.poll();
            for(Integer bus : stop2bus.get(stop.getCode())){
                if (stop.getBuses().contains(bus)){
                    continue;
                }
                for(int st = 0; st < (routes[bus].length > 500 ? 500 : routes[bus].length); st++){
                    if (routes[bus][st] == stop.getCode()){
                        continue;
                    }
                    StopNode stopNode = new StopNode();
                    stopNode.setCode(routes[bus][st]);
                    List<Integer> list = new LinkedList<Integer>();
                    for (Integer i : stop.getBuses()){
                        list.add(i);
                    }
                    stopNode.setBuses(list);
                    stopNode.getBuses().add(bus);
                    if(routes[bus][st] == T){
                        return stopNode;
                    }else{
                        stops.offer(stopNode);
                    }
                }
            }//for
        }//while
        return null;
    }

    private Map<Integer, List<Integer>> constructStop3Bus(int[][] routes){
        Map<Integer, List<Integer>> stop2bus = new HashMap<Integer, List<Integer>>();
        for(int bus = 0; bus < routes.length ; ++bus){
            for(int stop=0; stop < routes[bus].length; ++stop){
                if(stop2bus.containsKey(routes[bus][stop])){
                    stop2bus.get(routes[bus][stop]).add(bus);
                }else{
                    List<Integer> buses = new LinkedList<Integer>();
                    buses.add(bus);
                    stop2bus.put(routes[bus][stop], buses);
                }
            }
        }
        return stop2bus;
    }


    private class StopNode{
        private int code;
        private List<Integer> buses;

        public int getCode() {
            return code;
        }

        public void setCode(int code) {
            this.code = code;
        }

        public List<Integer> getBuses() {
            return buses;
        }

        public void setBuses(List<Integer> buses) {
            this.buses = buses;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            StopNode stopNode = (StopNode) o;

            if (code != stopNode.code) return false;
            return true;
        }

        @Override
        public int hashCode() {
            return code;
        }
    }
}
```