第一种思路：

```
public boolean carPooling(int[][] trips, int capacity) {
        int len = trips.length;
        int num[] = new int[1000];
        for (int i=0;i<len;i++) {
            // 行程中开始站加人，下车站减人[冗余处理]
            num[trips[i][1]] += trips[i][0];
            num[trips[i][2]] -= trips[i][0];
            
        }
        
        int max = 0;
        for (int i=0;i<num.length;i++) {
            if((max += num[i]) > capacity){
                return false;
            }
        }
        return true;
    }
```

第二种思路：

```
public boolean carPooling(int[][] trips, int capacity) {
        int len = trips.length;
        int num[] = new int[1000];
        
        for (int i=0;i<len;i++) {
            for (int j=trips[i][1];j<trips[i][2];j++) {
                // 每一个行程都记录当前的人数
                num[j] += trips[i][0];
            }
        }
        
        for (int i=0;i<num.length;i++) {
            if(num[i] > capacity){
                return false;
            }
        }
        return true;
    }
```

created 2019-9-3 20:13:26

v4.2 准入测试=