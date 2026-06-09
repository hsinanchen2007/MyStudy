将key作为hash的key存储，value是装着value和时间戳的对象数组，根据题目时间戳是递增的，只需要每次将value对象装进数组，get的时候根据时间戳进行二分。即可解决问题。
```
class TimeMap {

class Obj {
    String value;
    int timesamp;
    public Obj(String value,int timesamp){
        this.value = value;
        this.timesamp = timesamp;
    }
}
HashMap<String,ArrayList> map = new HashMap<String,ArrayList>();
    /** Initialize your data structure here. */
    public TimeMap() {

    }

    public void set(String key, String value, int timestamp) {
        Obj obj = new Obj(value,timestamp);
        if (map.containsKey(key)){
            ArrayList<Obj> arr = map.get(key);
            arr.add(obj);
            map.put(key,arr);
        }else {
            ArrayList<Obj> arr = new ArrayList<>();
            arr.add(obj);
            map.put(key,arr);
        }
    }

    public String get(String key, int timestamp) {
        ArrayList<Obj> arr = map.get(key);
        int left=0,right=arr.size()-1;
        while (left<=right){
            int mid = left+(right-left)/2;
            if (arr.get(mid).timesamp>timestamp){
                right = mid-1;
            }else if (arr.get(mid).timesamp==timestamp){
                return arr.get(mid).value;
            }else {
                left=mid+1;
            }
        }
         if (right >=0 && right<=arr.size()-1){
            return arr.get(right).value;
        }
        return "";
    }
}
````