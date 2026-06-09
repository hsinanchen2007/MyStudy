### 解题思路
![capture_20200203205025029.bmp](https://pic.leetcode-cn.com/ba4e2f046d887b01ea0b1f19cbad067c91a1a184b9100ee399abf3a56da0264d-capture_20200203205025029.bmp)
1. 用条件pass掉不符合的餐厅，然后加入到一个arratlist之中。
2. 用Collections.sort(list,new Comparator(){...})自定义一个排序方案
3. 因为不知道int[]的封装，所以用了Object到int[]的强转
4. 将排好序的餐厅转到ret中

### 代码

```java
class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        //restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]
        List list = new ArrayList();
        for(int[] restaurant:restaurants){
            if(veganFriendly==1){
                if(restaurant[2]==0){continue;}
            }
            if(restaurant[3]>maxPrice)continue;
            if(restaurant[4]>maxDistance)continue;
            list.add(restaurant);
        }
        Collections.sort(list,new Comparator(){
            @Override
            public int compare(Object o1,Object o2){
                int[] r1 = (int[])o1;
                int[] r2 = (int[])o2;
                if(r1[1]!=r2[1])return r2[1]-r1[1];
                else return r2[0]-r1[0];
            }
        });
        List<Integer> ret = new ArrayList<Integer>();
        for(int i=0;i<list.size();i++){
            int [] ele = (int[])list.get(i);
            ret.add(ele[0]);
        }
        return ret;
    }
}
```