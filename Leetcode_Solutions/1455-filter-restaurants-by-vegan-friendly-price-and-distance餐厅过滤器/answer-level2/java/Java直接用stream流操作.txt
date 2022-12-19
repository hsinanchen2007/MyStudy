```
class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
         List<Restaurant> restaurantList = new ArrayList<>();
        for (int[] restaurant : restaurants) {
            restaurantList.add(new Restaurant(restaurant[0], restaurant[1],
                    restaurant[2], restaurant[3], restaurant[4]));
        }
        return restaurantList.stream().filter(r -> r.veganFriendly >= veganFriendly
                && r.price <= maxPrice && r.distance <= maxDistance).sorted((o1, o2) -> {
            if (o1.rating == o2.rating) {
                return o2.id - o1.id;
            }
            return o2.rating - o1.rating;
        }).map(r -> r.id).collect(Collectors.toList());
    }
    
    private class Restaurant {
        int id;
        int rating;
        int veganFriendly;
        int price;
        int distance;

        public Restaurant(int id, int rating, int veganFriendly, int price, int distance) {
            this.id = id;
            this.rating = rating;
            this.veganFriendly = veganFriendly;
            this.price = price;
            this.distance = distance;
        }
    }
}
```
