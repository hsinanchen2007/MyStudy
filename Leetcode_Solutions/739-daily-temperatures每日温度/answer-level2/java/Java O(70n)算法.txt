利用温度的取值范围有限，可以使用map来存储具体温度在数组中的索引。AC代码：
```Java
class Solution {
    public int[] dailyTemperatures(int[] T) {
      int[] ans = new int[T.length];
      for(int i = 0; i < ans.length; i++) ans[i] = Integer.MAX_VALUE;
      Map<Integer,Integer> hmap = new HashMap<>();
      for(int i = T.length-1; i >= 0; i--){
        boolean haskey = false;
        for(int j = 100; j > T[i]; j--){
          if(hmap.containsKey(j)){
            haskey = true;
            int index = hmap.get(j);
            ans[i] = Math.min(index - i, ans[i]);
          }
        }
        if(!haskey) ans[i] = 0;
        hmap.put(T[i], i);
      }
      return ans;
    }
}
```
然鹅这个O(70n)算法只能击败30%的童鞋。。。。