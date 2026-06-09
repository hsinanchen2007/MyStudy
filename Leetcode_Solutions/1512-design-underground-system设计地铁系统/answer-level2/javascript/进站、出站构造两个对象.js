1. 构造数据结构
   进站对象checkInObj存放所有checkIn操作的站信息：
      以站名为key，value为数组，存放从该站checkIn的用户信息{id, t}
   出站对象checkOutObj存放所有checkOut操作的站信息：
      以站名为key，value为数组，存放从该站checkOut的用户信息{id, t}

2. checkIn操作 (id, stationName, t)
     判断checkInObj中key为stationName值是否存在，不存在的话，构造数组；
     stationName对应的value中添加用户信息{id, t}


3. checkOut操作 (id, stationName, t)
     判断checkOutObj中key为stationName值是否存在，不存在的话，构造数组；
     stationName对应的value中添加用户信息{id, t}

4. getAverageTime操作 (startStation, endStation)
   进站信息列表：checkInObj[startStation]
   出站信息列表：checkOutObj[endStation] 
   遍历checkInObj[startStation]中所有{id, t}是否checkInObj中存在，存在的话，累加时间