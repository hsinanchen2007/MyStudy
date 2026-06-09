#### 方法一：递归

我们可以使用深度优先搜索的方法，借助递归来解决这个问题。

设当前搜索到的状态为 `shopping(price, special, needs)`，其中 `price` 和 `special` 为题目中所述的物品的单价和捆绑销售的大礼包，而 `needs` 为当前需要的每种物品的数量。对于此时的 `needs`，我们可以考虑全部使用原价购买，总价即为 `price` 与 `needs` 对应位置相乘的结果；我们也可以使用大礼包，对于 `special` 中的某一个大礼包 `s`，如果 `s` 中的每种物品数量都不大于 `needs` 中对应物品数量，那么我们就可以使用这个大礼包 `s`。这样我们会递归地搜索状态 `shopping(price, special, needs')`，其中 `needs' = needs - s`，表示更新过的每种物品的数量。在状态 `shopping(price, special, needs)` 搜索完毕后，会返回其最小花费。

```Java [sol1]
public class Solution {
    public int shoppingOffers(List < Integer > price, List < List < Integer >> special, List < Integer > needs) {
        return shopping(price, special, needs);
    }
    public int shopping(List < Integer > price, List < List < Integer >> special, List < Integer > needs) {
        int j = 0, res = dot(needs, price);
        for (List < Integer > s: special) {
            ArrayList < Integer > clone = new ArrayList < > (needs);
            for (j = 0; j < needs.size(); j++) {
                int diff = clone.get(j) - s.get(j);
                if (diff < 0)
                    break;
                clone.set(j, diff);
            }
            if (j == needs.size())
                res = Math.min(res, s.get(j) + shopping(price, special, clone));
        }
        return res;
    }
    public int dot(List < Integer > a, List < Integer > b) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a.get(i) * b.get(i);
        }
        return sum;
    }
}
```

#### 方法二：记忆化搜索

我们可以发现，对于搜索状态 `shopping(price, special, needs)`，无论它是从哪个前置状态递归得来的，只要 `needs` 的值相同（`price` 和 `special` 在递归时是不会变的，我们将其放入搜索状态仅仅是为了方便使用这些变量），那么返回的最小花费也相同。因此我们可以使用一个哈希映射（HashMap）存储每个 `needs` 对应的最小花费，当我们递归进入一个搜索状态时，如果该状态中的 `needs` 没有出现过，那么我们进行搜索，并在搜索结束时将结果存入哈希映射；如果该状态中的 `needs` 出现过，那么我们就省去了搜索，直接返回哈希映射中对应的最小花费即可。

使用这种记忆化搜索的方法，可以将方法一中普通搜索的指数时间复杂度降低到多项式时间复杂度。

```Java [sol2]
public class Solution {
    public int shoppingOffers(List < Integer > price, List < List < Integer >> special, List < Integer > needs) {
        Map < List < Integer > , Integer > map = new HashMap();
        return shopping(price, special, needs, map);
    }
    public int shopping(List < Integer > price, List < List < Integer >> special, List < Integer > needs, Map < List < Integer > , Integer > map) {
        if (map.containsKey(needs))
            return map.get(needs);
        int j = 0, res = dot(needs, price);
        for (List < Integer > s: special) {
            ArrayList < Integer > clone = new ArrayList < > (needs);
            for (j = 0; j < needs.size(); j++) {
                int diff = clone.get(j) - s.get(j);
                if (diff < 0)
                    break;
                clone.set(j, diff);
            }
            if (j == needs.size())
                res = Math.min(res, s.get(j) + shopping(price, special, clone, map));
        }
        map.put(needs, res);
        return res;
    }
    public int dot(List < Integer > a, List < Integer > b) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a.get(i) * b.get(i);
        }
        return sum;
    }
}
```