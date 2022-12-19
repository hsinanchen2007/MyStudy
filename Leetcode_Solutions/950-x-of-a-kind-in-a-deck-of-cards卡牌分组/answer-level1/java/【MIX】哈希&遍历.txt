### 解题思路
1. 建立数字-频次哈希表, 遍历表长度因子进行判断
2. 对哈希表的频次求出最大公约数, 检测其值是否大于1

### 代码

```java []
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        // 表长遍历
        int N = deck.length;
        if(N <= 1)
            return false;
        if(N == 2)
            return deck[0] == deck[1];

        TreeSet<Integer> factors = getFactors(N);
        if(factors.isEmpty())
            return false;

        // 统计deck
        HashMap<Integer, Integer> rec = new HashMap<>();
        for(int d: deck){
            rec.put(d, rec.getOrDefault(d, 0)+1);
        }

        Set<Map.Entry<Integer, Integer>> entry = rec.entrySet();
        for(int f: factors){
            boolean flag = true;
            for(Map.Entry<Integer, Integer>e : entry){
                if(e.getValue() % f != 0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return true;
        }

        return false;
    }

    private TreeSet<Integer> getFactors(int N){
        TreeSet<Integer> factors = new TreeSet<>();
        for(int i=2; i<Math.sqrt(N)+1; ++i){
            if(N % i == 0){
                factors.add(i);
                factors.add(N/i);
            }
        }

        return factors;
    }
}
```
```python []
import math
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        N = len(deck)
        if N <= 1:
            return False
        if N == 2:
            return deck[0] == deck[1]

        def getFactors(N):
            factors = set()
        
            for i in range(2, int(math.sqrt(N))+1):
                if N % i == 0:
                    factors.add(i)
                    factors.add(N//i)
            return factors

        rec_vals = list(dict(collections.Counter(deck)).values())
        factors = getFactors(N)
        
        if factors == None:
            return False

        else:
            for f in factors:
                flag = True
                for r in rec_vals:
                    if r % f != 0:
                        flag = False
                        break
                if flag:
                    return True


        return False
```
```c++ []
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int N = deck.size();
        if(N == 1)
            return false;
        if(N == 2)
            return deck[0] == deck[1];
        
        // 建立数字-频次hashmap
        unordered_map<int, int> rec;
        for(int d: deck)
            rec[d]++;

        // 求出所有map.values的最大公约数
        auto mit = rec.begin();
        int res = mit->second;
        for(mit = next(rec.begin()); mit != rec.end(); ++mit){
            res = gcd(res, mit->second);
        }
        return res>1;
    }

    int gcd(int x, int y){
        if(x % y == 0)
            return y;
        return gcd(y, x%y);
    }
};
```