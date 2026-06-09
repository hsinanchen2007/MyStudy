### 解题思路
Linq语法自解释……

### 代码

```csharp
public class Solution {
    public IList<int> FilterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        List<Restaurants> listRest = new List<Restaurants>();
        foreach(var res in restaurants)
        {
            listRest.Add(new Restaurants(res[0], res[1], res[2], res[3], res[4]));
        }
        List<int>result = listRest.Where(item => item.veganFrindly > (veganFriendly == 1 ? 0 : -1) && 
                                                    item.price <= maxPrice && 
                                                    item.distance <= maxDistance)
                                    .OrderBy(item=>item.id)
                                    .OrderBy(item => item.rating)
                                    .Reverse().Select(i=>i.id)
                                    .ToList();
            return result;        
    }

    class Restaurants
    {
        public int id;
        public int rating;
        public int veganFrindly;
        public int price;
        public int distance;
        public Restaurants(int id_, int rating_, int veganFrindly_, int price_, int distance_)
        {
            id = id_;
            rating = rating_;
            veganFrindly = veganFrindly_;
            price = price_;
            distance = distance_;
        }
    }
}
```