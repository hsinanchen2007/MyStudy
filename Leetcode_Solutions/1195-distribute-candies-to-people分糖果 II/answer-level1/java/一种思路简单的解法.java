### 解题思路
将每个人的分到的糖果放到HASHMAP里面，初始化都是0；
然后开始遍历，分别填充到HASHMAP中每个人的value里面；
最后定义一个数组，把HASHMAP中的值灌入数组当中，返回。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<num_people;i++){
            map.put(i,0);
        }
        int rest = candies;
        int val = 1;
        int i = 0;
        while(rest>0){
            if(rest>=val){
            int tmp = map.getOrDefault(i%num_people,0);
            map.put(i%num_people,tmp+val);
            rest = rest-val;
            }else{
            map.put(i%num_people,map.getOrDefault(i%num_people,0)+rest);
            break;
            }
            i++;
            val++;            
        }
        int[] res = new int[num_people];
        for(int j=0;j<num_people;j++){
            res[j] = map.getOrDefault(j,0);
        }
        return res;
    }
}
```