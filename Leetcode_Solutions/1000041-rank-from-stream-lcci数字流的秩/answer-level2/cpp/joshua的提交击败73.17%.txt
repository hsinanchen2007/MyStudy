### 解题思路
joshua告诉你：这是一道简单题，只要用map保存好每个数的次数就行，map的键会自动排序

### 代码

```cpp
class StreamRank {
public:
    StreamRank() {

    }
    
    void track(int x) {
        data[x]++;
    }
    
    int getRankOfNumber(int x) {
        map<int, int>::iterator it;
        int sum = 0;
        for(it = data.begin(); it != data.end() && it->first <= x; it++) {
            sum += it->second;
        }
        return sum;
    }
private:
    map<int, int> data;
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
```