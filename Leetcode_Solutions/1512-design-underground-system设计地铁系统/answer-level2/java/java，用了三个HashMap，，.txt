    
    class UndergroundSystem {
        HashMap<Integer, String> startStation;   // 存这个人的始发站
        HashMap<Integer, Integer> startTime;     // 存这个人什么时候上的车
        HashMap<String, List<Integer>> history;  // 存每一对站的时间
        public UndergroundSystem() {
            startStation = new HashMap<>();
            startTime = new HashMap<>();
            history = new HashMap<>();
        }
        
        public void checkIn(int id, String stationName, int t) {
            if(startTime.containsKey(id) && startTime.get(id) == t) {
                if(!stationName.equals(startStation.get(id))) { //同一个时间但是地铁站不同，无效
                    return;
                }
            }
            startStation.put(id, stationName);
            startTime.put(id, t);
        }
        
        public void checkOut(int id, String stationName, int t) {
            int time = t - startTime.get(id);   // 下车记录做了多长时间的车
            String s = startStation.get(id);
            // 这一对站点用字典序拼起来，因为站与站乘车是双向的，防止只记录一个方向的乘车
            String temp = s.compareTo(stationName) < 0 ? s + stationName : stationName + s;
            if(history.containsKey(temp)) {
                history.get(temp).add(time);
            }else {
                List<Integer> list = new ArrayList<>();
                list.add(time);
                history.put(temp, list);
            }
            startStation.remove(id);
            startTime.remove(id);
        }
        
        public double getAverageTime(String startStation, String endStation) {
            String temp = startStation.compareTo(endStation) < 0 ? startStation + endStation : endStation + startStation;
            if(history.containsKey(temp)) {
                List<Integer> list = history.get(temp);
                double res = 0;
                for(int i = 0;i < list.size();i++) {
                    res += list.get(i);
                }
                return res / list.size();
            }
            return 0;
        }
    }
