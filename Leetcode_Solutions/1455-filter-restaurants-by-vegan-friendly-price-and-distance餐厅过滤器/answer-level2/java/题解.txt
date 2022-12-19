### 解题思路
很简单的模拟题，就是老老实实过滤三种情况，然后把结果按照rating排序，再按照编号排序，但是java里好像没有一个特别好的数据结构能够存储单个的键值对，我就用二维数组存了一下，然后用lambda表达式重写了sort

### 代码

```java
class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int len = restaurants.length;
        int len1 = len;
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            if (veganFriendly == 1 && restaurants[i][2] != 1) {res[i] = 1; len1--;}
            else if (restaurants[i][3] > maxPrice || restaurants[i][4] > maxDistance) {res[i] = 1; len1--;}
        }
        int[][] arr= new int[len1][2];
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (res[i] == 0) {
                arr[j][0] = restaurants[i][0];
                arr[j][1] = restaurants[i][1];
                j++;
            }
        }
        Arrays.sort(arr, (a, b) -> (b[1] != a[1]) ? (b[1] - a[1]) : (b[0] - a[0]));
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            l.add(arr[i][0]);
        }
        return l;
    }
}
```