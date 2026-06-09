### 解题思路
满足条件的加入到优先队列即可，注意优先队列的comparable的的条件即可，这题其实蛮esay的。

### 代码

```java
class Solution {
    private static class Restaurants implements Comparable<Restaurants>{
        int id;
        int rating;
        int veganFriendly;
        int price;
        int distance;

        public Restaurants(int id, int rating, int veganFriendly, int price, int distance) {
            this.id = id;
            this.rating = rating;
            this.veganFriendly = veganFriendly;
            this.price = price;
            this.distance = distance;
        }

        @Override
        public int compareTo(Restaurants o) {
            if (o.rating - this.rating == 0){
                return o.id - this.id;
            }
            return o.rating - this.rating;
        }
    }

    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        List<Integer> res = new ArrayList<>();
        Queue<Restaurants> pq = new PriorityQueue<>();
        for (int i = 0; i < restaurants.length; i++) {
            int[] restaurant = restaurants[i];
            // 传入是素，餐馆不是素不加入
            if (veganFriendly == 1 && restaurant[2] != 1){
                continue;
            }
            if (restaurant[3] > maxPrice){
                continue;
            }
            if (restaurant[4] > maxDistance){
                continue;
            }
            pq.offer(new Restaurants(restaurant[0],restaurant[1],restaurant[2],restaurant[3],restaurant[4]));
        }
        while (!pq.isEmpty()){
            res.add(pq.poll().id);
        }
        return res;
    }
}
```