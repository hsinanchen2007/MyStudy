### 解题思路
1. 使用哈希表
2. 使用multiset

### 代码

```c++ []
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        vec.push_back(number);
        rec[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(int i=0; i<vec.size(); ++i){
            int e = value-vec[i];
            if(e == vec[i]){
                if(rec[e]>1)
                    return true;
                else
                    continue; 
            }
            else{
                if(rec.find(e) != rec.end())
                    return true;
                else
                    continue;
            }
        }
        return false;
    }

private:
    vector<int> vec;
    map<int, int> rec;
};
/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```
```c++ []
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        rec.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        // 双指针查询
        if(rec.empty())
            return false;
        auto p = rec.begin();
        auto q = prev(rec.end());
        while(p != q){
            int temp = *p+*q;
            if(temp == value)
                return true;
            else if(temp < value)
                ++p;
            else
                --q;
        }
        return false;
    }

private:
    multiset<int> rec;

};

// 关闭同步缓存流
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
```
```java []
class TwoSum {

    /** Initialize your data structure here. */
    public TwoSum() {
        this.map = new HashMap<>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        map.put(number, map.getOrDefault(number, 0)+1);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for(int e: map.keySet()){
            int v = value-e;
            if(map.containsKey(v)){
                if(v == e && map.get(v)>1){
                    return true;
                }
                else if(v != e)
                    return true;
                else
                    continue;
            }
        }
        return false;
    }

    private List<Integer> rec;
    private HashMap<Integer, Integer> map;
}
```
```python []
class TwoSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.rec = dict()


    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        if number in self.rec.keys():
            self.rec[number] +=1
        else:
            self.rec[number] = 1


    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        for k in self.rec.keys():
            e = value - k
            if e in self.rec.keys():
                if e==k and self.rec[e]>1:
                    return True
                elif e != k:
                    return True
                else:
                    continue
        return False
```