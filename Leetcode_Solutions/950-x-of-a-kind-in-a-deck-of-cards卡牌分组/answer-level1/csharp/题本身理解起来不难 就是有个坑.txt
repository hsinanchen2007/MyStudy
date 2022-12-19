![\[3$EJK0WSC\[9$J6PV2ZQNMW.png](https://pic.leetcode-cn.com/ee7c44ef21f2375cd85e2af54e02a2b3715ffa81b86cd2c916ac190d68e949cd-%5B3$EJK0WSC%5B9$J6PV2ZQNMW.png)

效率一般，直接说思路
先说一下满足题意的几种情况：
    1. 相同元素放在一起分组之后 每组元素数量相同 （这个是普遍可以想到的）
    2. 相同元素放在一起分组之后 每组元素数量可以整除 （这是个坑）
    举例来说: [1,1,2,2,2,2] 可以分为 [1,1]、[2,2]、[2,2] 2的数量可以整除1的数量

思路：如果按照上述说的两种情况来做判断的话，第一种还可以，但是第二种情况就比较烦了(涉及到除 取余 两数交换找最大这三个操作)
所以这里采用求最大公约数的方法 即 如果元素间满足最大公约数不为1 则成立 这样判断直接满足上述两种情况

```
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        if(deck.Length <= 1){
            return false;
        }
        Dictionary<int, int> dic = new Dictionary<int, int>();
        foreach(var item in deck){
            if(!dic.ContainsKey(item)){
                dic.Add(item, 0);
            }
            dic[item]++;
        }

        int[] arr = dic.Values.ToArray();
        for(int i = 1; i < arr.Length; i++){
            if(gcd(arr[i-1], arr[i]) == 1){
                return false;
            }
        }

        return arr[0] > 1 ? true : false;
    }

    public int gcd(int a, int b){
        if(a < b){
            int temp = b;
            b = a;
            a = temp;
        }

        if(a % b != 0){
            return gcd(a % b, b);
        }

        return b;
    }
}
```
