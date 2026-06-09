把值和时间戳用一个对象data来存储。利用hashmap存储key为字符串key，值为data数组。
```
class Data{
        public String value;
        public int timestamp;
        public Data(String value, int timestamp){
            this.value = value;this.timestamp = timestamp;
        }
    }
    public Map<String,List<Data>> data;
    public TimeMap() {
        data = new LinkedHashMap<String,List<Data>>();
    }
    
    public void set(String key, String value, int timestamp) {
        Data d = new Data(value, timestamp);
        List<Data> tmp;
        if(data.get(key) == null){
            tmp = new ArrayList<Data>();
            tmp.add(d);
            data.put(key, tmp);
        }else{
            tmp = data.get(key);
            tmp.add(d);
            data.put(key, tmp);
        }

    }

```


至于查找有两种方案，一种暴力查找，因为要找时间戳小于等于给定值的value，因此考虑从后往前查找
```
public String get(String key, int timestamp) {
        List<Data> tmp = data.get(key);
        int n = tmp.size();
        if(n == 0) return "";
        for(int i=n-1;i>=0;i--) {
        	if(tmp.get(i).timestamp <= timestamp) {
        		return tmp.get(i).value;
        	}
        }
        return "";
    }
```


另一种利用二分法查找值最后一个小于等于给定值的数据
```
public String get(String key, int timestamp) {
        List<Data> tmp = data.get(key);
        int n = tmp.size();
        String result = "";
        if(n == 0) return result;
        int min = 0;int max = n-1;
        while(min <= max){
            int mid = (min+max)/2;
            if(tmp.get(mid).timestamp>timestamp){
                max = mid-1;
            }else{
                if((mid == n - 1) || (tmp.get(mid+1).timestamp > timestamp))
                    return tmp.get(mid).value;
                else
                    min = mid+1;
            }
        }
        return result;
    }
```


然而出现了一个很奇怪的问题——
暴力查找耗时188 ms，击败99%
二分查找耗时226 ms，击败61%
先不管我的二分查找是不是写的有问题……我能用暴力查找直接击败99%这点就很奇怪了，猜想是不是测试数据存在一定的偏向性